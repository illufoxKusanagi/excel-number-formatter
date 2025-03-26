#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Image Converter");
  resize(400, 200);

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
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->hasUrls()) {
    event->acceptProposedAction();
  }
}

void MainWindow::readExcel() {
  QString filePath = QFileDialog::getOpenFileName(nullptr, "Pilih file", "",
                                                  "Excel Files (*.xlsx)");
  if (filePath.isEmpty()) {
    QMessageBox::warning(nullptr, "Error", "Tidak ada file yang dipilih");
    return;
  }

  QXlsx::Document xlsx(filePath);
  if (!xlsx.load()) {
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
  processExcel();
}