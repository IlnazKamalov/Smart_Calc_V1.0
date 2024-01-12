#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Calc_main/s21_stack.h"
#ifdef __cplusplus
}
#endif
#include <QMainWindow>
#include <QVector>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
 private slots:

  void digits_numbers();
  void digit_dot();
  void del();
  void digit_result();
  void operations();
  void on_Graphic_do_clicked();
};

#endif  // MAINWINDOW_H
