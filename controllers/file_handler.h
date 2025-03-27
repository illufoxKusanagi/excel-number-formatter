#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "xlsxdocument.h"
#include <QCoreApplication>
#include <QDir>
#include <QMessageBox>
#include <QObject>
#include <QRegularExpression>
#include <QString>
#include <QVector>

class FileHandler : public QObject {
  Q_OBJECT

public slots:
  void procesFile(QString filePath);
  void cancelProcess();

signals:
  void resultReady(bool success, const QStringList &sheetNames);
  void processingFinished();
  void progressUpdate(int percentage);
  void processingCanceled();

public:
  FileHandler();
  ~FileHandler();

private:
  bool m_isCanceled = false;
  QXlsx::Document *m_xlsx = nullptr;
  QString m_currentFilePath;
  void deleteFirstFourRows(QString sheetName);
  void processExcel(QString sheetName);
  void cleanupDocument();
  void clearMemoryCache();
};

#endif // FILE_HANDLER_H
