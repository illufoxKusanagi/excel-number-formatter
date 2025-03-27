#include "file_handler.h"

FileHandler::FileHandler() {}

FileHandler::~FileHandler() { cleanupDocument(); }

void FileHandler::cleanupDocument() {
  if (m_xlsx) {
    delete m_xlsx;
    m_xlsx = nullptr;
  }
}

void FileHandler::procesFile(QString filePath) {
  m_isCanceled = false;
  emit progressUpdate(0);
  m_currentFilePath = filePath;
  m_xlsx = new QXlsx::Document(filePath);
  bool success = m_xlsx->load();

  // Check if canceled early
  if (m_isCanceled) {
    emit processingCanceled();
    emit processingFinished();
    return;
  }

  emit progressUpdate(10);

  QStringList sheetNames;
  if (success) {
    sheetNames = m_xlsx->sheetNames();
    for (int i = 0; i < sheetNames.size(); i++) {
      QCoreApplication::processEvents();
      if (m_isCanceled) {
        emit processingCanceled();
        emit processingFinished();
        return;
      }
      int progress = 10 + (i + 1) * 80 / sheetNames.size();
      emit progressUpdate(progress);
      deleteFirstFourRows(sheetNames[i]);
      processExcel(sheetNames[i]);
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
  if (!m_isCanceled) {
    emit resultReady(success, sheetNames);
    QDir dir("F:/matkul/sem_6/AppProject/trainLoggerFormatter/output");
    if (!dir.exists()) {
      dir.mkpath(".");
    }
    bool saveSuccess = m_xlsx->saveAs(
        "F:/matkul/sem_6/AppProject/trainLoggerFormatter/output/output.xlsx");
    if (!saveSuccess) {
      qDebug() << "Failed to save output file";
    }
  }
  cleanupDocument();
  emit processingFinished();
}

void FileHandler::cancelProcess() {
  qDebug() << "Canceling processing...";
  m_isCanceled = true;
}

void FileHandler::deleteFirstFourRows(QString sheetName) {
  if (!m_xlsx || !m_xlsx->selectSheet(sheetName)) {
    qDebug() << "Error: Could not select sheet" << sheetName;
    return;
  }

  // Get sheet dimensions
  QXlsx::CellRange range = m_xlsx->dimension();
  if (!range.isValid()) {
    qDebug() << "Empty sheet or invalid dimension" << sheetName;
    return;
  }

  int maxRow = range.lastRow();
  int maxCol = range.lastColumn();

  // qDebug() << "Sheet dimensions:" << maxRow << "rows," << maxCol <<
  // "columns";
  int currentRow = 6;
  int currentCol = 1;
  // Implement your Excel processing logic here
  // qDebug() << "Processing sheet" << sheetName;
  for (int col = 0; col <= maxCol; col++) {
    for (int row = 5; row <= maxRow; row++) {
      QVariant value = m_xlsx->read(row, col);
      QString cellString = value.toString();
      QRegularExpression numericPattern("^[0-9]*[.,]?[0-9]+$");
      // Matches integers or floats (e.g., 12, .5, 12.34)
      if (numericPattern.match(cellString).hasMatch()) {
        QString normalized = cellString;
        normalized.replace(',', '.'); // Replace comma with dot
        bool conversionOk = false;
        double numValue = normalized.toDouble(&conversionOk);
        // qDebug() << "Cell value at" << row << col << "is a "
        //          << (numValue == (int)numValue ? "whole number" : "float")
        //          << " value:" << numValue;
        if (conversionOk) {
          m_xlsx->write(row, col, numValue);
        }
      }
    }
  }
  // while (!m_xlsx->read(currentRow, currentCol).isNull()) {
  //   currentRow++;
  //   currentCol++;
  // }

  m_xlsx->save(); // Simpan perubahan ke file
  // QMessageBox::information(
  //     nullptr, "Success",
  //     "Format kolom berhasil diubah ke angka mulai dari baris ke-6");
  // qDebug() << "Format kolom berhasil diubah ke angka mulai dari baris ke-6";

  // // Process the sheet - move all content up by 4 rows
  // for (int row = 5; row <= maxRow; ++row) {
  //   for (int col = 1; col <= maxCol; ++col) {
  //     // Read cell value at source position
  //     QVariant value = m_xlsx->read(row, col);
  //     if (value.isNull())
  //       continue;

  //     // Move content up by 4 rows
  //     int targetRow = row - 4;

  //     // Write the cell value to the new location
  //     m_xlsx->write(targetRow, col, value);

  //     // We can't easily copy formatting with QXlsx without using cellAt
  //     // So we're just copying values

  //     // Clear the original cell
  //     m_xlsx->write(row, col, QVariant());
  //   }

  //   // Don't save here - we'll save at the end of processing
  //   // This avoids modifying the original file
  //   // m_xlsx->save(); <- Remove this
  // }
  // qDebug() << "Deleted first 4 rows from sheet" << sheetName;
}

void FileHandler::processExcel(QString sheetName) {
  // Now you can access m_xlsx directly here
  if (!m_xlsx || !m_xlsx->selectSheet(sheetName)) {
    qDebug() << "Error: Could not select sheet" << sheetName;
    return;
  }

  // Example: Read data from the sheet
  // QXlsx::Cell *cell = m_xlsx->cellAt(1, 1);
  // if (cell) {
  //     qDebug() << "Value at A1:" << cell->value().toString();
  // }

  // Save changes if needed
  // m_xlsx->save();
}