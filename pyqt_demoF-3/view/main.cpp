#include "mainwindow.h"
#include "uploadwindow.h"
#include "patientwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    UploadWindow w;
    //PatientWindow w;
    w.show();
    return a.exec();
}
