#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <QMainWindow>

namespace Ui {
class patientInfo;
}

class patientInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit patientInfo(QWidget *parent = nullptr);
    ~patientInfo();

private:
    Ui::patientInfo *ui;
};

#endif // PATIENTINFO_H
