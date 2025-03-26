#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Excel converter");
  resize(600, 400);

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  label = new QLabel("Drag and drop your excel file (.xlsx) here \n or press "
                     "the button to browse file",
                     this);
  label->setAlignment(Qt::AlignCenter);

  button = new QPushButton("Browse file", this);

  layout->addWidget(label);
  layout->addWidget(button);
  connect(button, &QPushButton::clicked, this, &MainWindow::readExcel);
  setAcceptDrops(true);

  fileHandler = new FileHandler();
  fileHandler->moveToThread(&thread);

  connect(fileHandler, &FileHandler::resultReady, this,
          &MainWindow::handleExcelResult);
  connect(fileHandler, &FileHandler::progressUpdate, this,
          [this](int percentage) {
            if (progress && progress->isVisible()) {
              progress->setValue(percentage);
            }
          });
  connect(fileHandler, &FileHandler::processingCanceled, this, [this]() {
    QMessageBox::information(this, "Processing Canceled",
                             "File processing has been canceled.");
  });
  connect(fileHandler, &FileHandler::processingFinished, [this]() {
    if (progress)
      progress->close();
  });
  thread.start();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->hasUrls()) {
    event->acceptProposedAction();
  }
}

MainWindow::~MainWindow() {
  // Properly shut down the thread
  if (thread.isRunning()) {
    thread.quit();     // Ask the thread to quit
    thread.wait(3000); // Wait up to 3 seconds for it to finish

    // If thread is still running after waiting
    if (thread.isRunning()) {
      thread.terminate(); // Force termination (should be avoided if possible)
    }
  }

  // Clean up the progress dialog if it exists
  if (progress) {
    progress->close();
    delete progress;
    progress = nullptr;
  }
}

void MainWindow::readExcel() {
  QString filePath = QFileDialog::getOpenFileName(nullptr, "Pilih file", "",
                                                  "Excel Files (*.xlsx)");
  if (filePath.isEmpty()) {
    QMessageBox::warning(nullptr, "Error", "Tidak ada file yang dipilih");
    return;
  }
  startExcelProcessing(filePath);
}

void MainWindow::startExcelProcessing(const QString &filePath) {
  progress =
      new QProgressDialog("Loading Excel file...", "Cancel", 0, 100, this);
  progress->setWindowModality(Qt::WindowModal);
  progress->setValue(0);
  progress->setMinimumDuration(0);
  progress->show();
  connect(progress, &QProgressDialog::canceled, this,
          &MainWindow::cancelProcessing);
  QMetaObject::invokeMethod(fileHandler, "procesFile", Qt::QueuedConnection,
                            Q_ARG(QString, filePath));
}

void MainWindow::handleExcelResult(bool success,
                                   const QStringList &sheetNames) {
  if (!success) {
    QMessageBox::warning(this, "Error", "Failed to open file!");
    return;
  }
  processExcel();
}

void MainWindow::processExcel() {
  QMessageBox::information(this, "Success", "Data processed successfully!");
}

void MainWindow::dropEvent(QDropEvent *event) {
  QList<QUrl> urls = event->mimeData()->urls();
  if (urls.isEmpty())
    return;
  QString filePath = urls.first().toLocalFile();
  startExcelProcessing(filePath);
}

void MainWindow::cancelProcessing() {
  int ret = QMessageBox::warning(
      this, tr("Cancel Operation"),
      tr("Mid-process cancellation is not supported with QXlsx.\n"
         "Do you want to forcibly cancel and terminate the operation?"),
      QMessageBox::Yes | QMessageBox::No);

  if (ret == QMessageBox::Yes) {
    // Force the FileHandler thread to stop
    // (If running in the same thread, just set m_isCanceled.)
    if (thread.isRunning()) {
      thread.requestInterruption();
      thread.terminate(); // Not recommended, but sometimes necessary
      thread.wait(1000);
      QMessageBox::information(this, "Processing Canceled",
                               "File processing has been canceled.");
    }
    QMetaObject::invokeMethod(fileHandler, "cancelProcess",
                              Qt::QueuedConnection);
  }
}