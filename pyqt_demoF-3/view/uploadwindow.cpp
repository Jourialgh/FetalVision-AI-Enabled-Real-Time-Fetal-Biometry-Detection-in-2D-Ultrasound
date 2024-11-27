#include "uploadwindow.h"
#include "ui_uploadwindow.h"

UploadWindow::UploadWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UploadWindow)
{
    ui->setupUi(this);
}

UploadWindow::~UploadWindow()
{
    delete ui;
}
