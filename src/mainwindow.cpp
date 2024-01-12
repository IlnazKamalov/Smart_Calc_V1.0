#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QString>
#include "./ui_mainwindow.h"
#include "qcustomplot.h"
#include <locale.h>
#include <Calc_main/s21_stack.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->result_show->setText("");

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_tochka,SIGNAL(clicked()),this,SLOT(digit_dot()));
    connect(ui->pushButton_PLUSMINUS,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_PLUS,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_MIN,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_DEL,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_UMN,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ac,SIGNAL(clicked()), this, SLOT(del()));
    connect(ui->pushButton_RAVNO,SIGNAL(clicked()), this, SLOT(digit_result()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_leftB, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_rightB, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(operations()));
}

MainWindow::~MainWindow() {
  delete ui;
}


void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_str = ui->result_show->text() + button->text();
  ui->result_show->setText(new_str);
}

void MainWindow::digit_dot() {
  if (!(ui->result_show->text().endsWith('.')))
    ui->result_show->setText(ui->result_show->text() + ".");
}


void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    new_label = ui->result_show->text();

    if (button->text() == "/" && !(ui->result_show->text().endsWith("÷")) &&
         !(ui->result_show->text().endsWith("/"))) {
       new_label += "/";
     } else if (button->text() == "*" && !(ui->result_show->text().endsWith("*"))) {
       new_label += "*";
    } else if (button->text() == "x" && !(ui->result_show->text().endsWith("x"))) {
       new_label += "x";
     } else if (button->text() == "+" && !(ui->result_show->text().endsWith("+"))) {
       new_label += "+";
     } else if (button->text() == "-" && !(ui->result_show->text().endsWith("-"))) {
       new_label += "-";
     } else if (button->text() == "^" && !(ui->result_show->text().endsWith("^"))) {
       new_label += "^";
     } else if (button->text() == "%" && !(ui->result_show->text().endsWith("%"))) {
       new_label += "%";
     } else if (button->text() == "(") {
       new_label += "(";
     } else if (button->text() == ")") {
       new_label += ")";
     } else if (button->text() == "sin" && !(ui->result_show->text().endsWith("sin"))) {
       new_label += "sin";
     } else if (button->text() == "cos" && !(ui->result_show->text().endsWith("cos"))) {
       new_label += "cos";
     } else if (button->text() == "tan" && !(ui->result_show->text().endsWith("tan"))) {
       new_label += "tan";
     } else if (button->text() == "log" && !(ui->result_show->text().endsWith("log"))) {
       new_label += "log";
     } else if (button->text() == "asin" && !(ui->result_show->text().endsWith("asin"))) {
       new_label += "asin";
     } else if (button->text() == "acos" && !(ui->result_show->text().endsWith("acos"))) {
       new_label += "acos";
     } else if (button->text() == "atan" && !(ui->result_show->text().endsWith("atan"))) {
       new_label += "atan";
     } else if (button->text() == "ln" && !(ui->result_show->text().endsWith("ln"))) {
       new_label += "ln";
     } else if (button->text() == "sqrt" && !(ui->result_show->text().endsWith("sqrt"))) {
      new_label += "sqrt";
     } else if (button->text() == "+/-") {
       new_label += "*(-1)";
     }
     ui->result_show->setText(new_label);
   }


void MainWindow::digit_result() {
  QString str = ui->result_show->text();
  QByteArray strBytes = str.toUtf8();
  char *strData = strBytes.data();
  QString result;

  ui->result_show->clear();
  ui->result_show_2->setText(str);

  if (str.length() > 1) {
    setlocale(LC_NUMERIC, "C");
    if (main_validator(strData) == 0) {
      double x_value = ui->doubleSpinBoxX->value();
      int inval = 0;
      double res = s21_main(strData, x_value, &inval);
      if (inval == 1) {
        ui->result_show->setText("Invalid Input");
      } else {
        result = QString::number(res, 'g', 10);
        if (std::isinf(res) || std::isnan(res) || res != res) {
          ui->result_show->setText("");
        } else {
          ui->result_show->setText(result);
        }
      }
    } else {
      ui->result_show->clear();
    }
  } else {
    ui->result_show->setText("Invalid Input");
  }
}

void MainWindow::del() {
  ui->result_show->clear();
}

void MainWindow::on_Graphic_do_clicked() {
  double xBegin = ui->Graph_X->value();
  double xEnd = ui->Graph_Y->value();
  double h = 0.1;
  int n = static_cast<int>((xEnd - xBegin) / h) + 2;
  QVector<double> x(n), y(n);

  QString str = ui->result_show->text();
  QByteArray strBytes = str.toUtf8();
  char *strData = strBytes.data();

  if (str.length() > 1) {
    if (main_validator(strData) == 0) {
      double x_val = xBegin;
      int inval = 0;
      for (int i = 0; i < n; i++) {
        x[i] = x_val;
        y[i] = s21_main(strData, x_val, &inval);
        x_val += h;
      }
    } else {
      ui->result_show->clear();
    }
  } else {
    ui->result_show->clear();
  }

  ui->Graph->xAxis->setRange(xBegin, xEnd);
  ui->Graph->yAxis->setRange(xBegin, xEnd);

  ui->Graph->clearGraphs();
  ui->Graph->addGraph();
  ui->Graph->graph(0)->setData(x, y);
  ui->Graph->replot();
}
