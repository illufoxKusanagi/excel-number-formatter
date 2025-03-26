#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "xlsxdocument.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QMimeData>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

private slots:
  void readExcel();

public:
  MainWindow(QWidget *parent = nullptr);

protected:
  void dragEnterEvent(QDragEnterEvent *event) override;
  void dropEvent(QDropEvent *event) override;

private:
  QLabel *label;
  QPushButton *button;
  QSlider *qualitySlider;
  QSpinBox *qualityValue;
  void processExcel();
};
#endif // MAINWINDOW_H
