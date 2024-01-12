#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) { 
    QApplication application(argc, argv);
   
    MainWindow window;
    window.setWindowTitle("Smart Calculator v1.0");
    window.show();
    return application.exec();
}
