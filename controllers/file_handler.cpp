#include "file_handler.h"

FileHandler::FileHandler() {}

void FileHandler::procesFile(QString filePath) {
  m_isCanceled = false;
  emit progressUpdate(0);
  QXlsx::Document xlsx(filePath);
  bool success = xlsx.load();

  // Check if canceled early
  if (m_isCanceled) {
    emit processingCanceled();
    emit processingFinished();
    return;
  }

  emit progressUpdate(10);

  QStringList sheetNames;
  if (success) {
    sheetNames = xlsx.sheetNames();
    for (int i = 0; i < sheetNames.size(); i++) {
      QCoreApplication::processEvents();
      if (m_isCanceled) {
        emit processingCanceled();
        emit processingFinished();
        return;
      }
      int progress = 10 + (i + 1) * 80 / sheetNames.size();
      emit progressUpdate(progress);
      qDebug() << sheetNames[i];
      if (m_isCanceled) {
        emit processingCanceled();
        emit processingFinished();
        return;
      }
    }
    emit progressUpdate(95);
  }
  if (m_isCanceled) {
    emit processingCanceled();
    emit processingFinished();
    return;
  }
  emit progressUpdate(100);
  if (!m_isCanceled)
    emit resultReady(success, sheetNames);
  emit processingFinished();
}

void FileHandler::cancelProcess() {
  qDebug() << "Canceling processing...";
  m_isCanceled = true;
}