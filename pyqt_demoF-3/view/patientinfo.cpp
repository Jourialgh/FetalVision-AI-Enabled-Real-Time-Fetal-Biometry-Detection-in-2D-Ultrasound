#include "patientinfo.h"
#include "ui_patientinfo.h"

patientInfo::patientInfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::patientInfo)
{
    ui->setupUi(this);
}

patientInfo::~patientInfo()
{
    delete ui;
}
