#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "xlsxdocument.h"
#include <QCoreApplication>
#include <QObject>
#include <QString>


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

private:
  bool m_isCanceled = false;
};

#endif // FILE_HANDLER_H
