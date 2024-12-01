/********************************************************************************
** Form generated from reading UI file 'patientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTWINDOW_H
#define UI_PATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *back_widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *main_widget;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *title_label;
    QPushButton *download_pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *DOB_label;
    QLabel *name_label;
    QLabel *ID_label;
    QLabel *by_label;
    QLabel *inst_label;
    QLabel *date_label;
    QVBoxLayout *verticalLayout_7;
    QLabel *measurements_label;
    QGridLayout *gridLayout_2;
    QLabel *hc_label;
    QLabel *Thc_label;
    QLabel *Tfl_label;
    QLabel *Tofd_label;
    QLabel *Tbpd_label;
    QLabel *bpd_label;
    QLabel *ofd_label;
    QLabel *fl_label;
    QVBoxLayout *verticalLayout_8;
    QLabel *US_label;
    QVBoxLayout *verticalLayout_9;
    QLabel *US1_label;
    QLabel *US2_label;
    QLabel *US3_label;
    QLabel *US4_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientWindow)
    {
        if (PatientWindow->objectName().isEmpty())
            PatientWindow->setObjectName(QString::fromUtf8("PatientWindow"));
        PatientWindow->resize(800, 600);
        centralwidget = new QWidget(PatientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        back_widget = new QWidget(centralwidget);
        back_widget->setObjectName(QString::fromUtf8("back_widget"));
        back_widget->setStyleSheet(QString::fromUtf8("QWidget#back_widget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(back_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        main_widget = new QWidget(back_widget);
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        main_widget->setStyleSheet(QString::fromUtf8("QWidget#main_widget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(main_widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(-1);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, -1, 0, 0);
        title_label = new QLabel(main_widget);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Times New Roman\";\n"
"qproperty-alignment: 'AlignCenter';"));
        title_label->setMargin(0);
        title_label->setIndent(-1);

        gridLayout_3->addWidget(title_label, 0, 1, 1, 1);

        download_pushButton = new QPushButton(main_widget);
        download_pushButton->setObjectName(QString::fromUtf8("download_pushButton"));
        download_pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(download_pushButton, 0, 2, 1, 1);

        widget = new QWidget(main_widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(50, 50));
        widget->setMaximumSize(QSize(60, 60));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/assets/assets/logo2.png);"));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        gridLayout_3->setColumnStretch(1, 1);

        verticalLayout_6->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DOB_label = new QLabel(main_widget);
        DOB_label->setObjectName(QString::fromUtf8("DOB_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DOB_label->sizePolicy().hasHeightForWidth());
        DOB_label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        DOB_label->setFont(font);
        DOB_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(DOB_label, 2, 0, 1, 1);

        name_label = new QLabel(main_widget);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        sizePolicy1.setHeightForWidth(name_label->sizePolicy().hasHeightForWidth());
        name_label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setBold(true);
        name_label->setFont(font1);
        name_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        name_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(name_label, 0, 0, 1, 1);

        ID_label = new QLabel(main_widget);
        ID_label->setObjectName(QString::fromUtf8("ID_label"));
        sizePolicy1.setHeightForWidth(ID_label->sizePolicy().hasHeightForWidth());
        ID_label->setSizePolicy(sizePolicy1);
        ID_label->setFont(font);
        ID_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(ID_label, 1, 0, 1, 1);

        by_label = new QLabel(main_widget);
        by_label->setObjectName(QString::fromUtf8("by_label"));
        sizePolicy1.setHeightForWidth(by_label->sizePolicy().hasHeightForWidth());
        by_label->setSizePolicy(sizePolicy1);
        by_label->setFont(font);
        by_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(by_label, 3, 1, 1, 1);

        inst_label = new QLabel(main_widget);
        inst_label->setObjectName(QString::fromUtf8("inst_label"));
        sizePolicy1.setHeightForWidth(inst_label->sizePolicy().hasHeightForWidth());
        inst_label->setSizePolicy(sizePolicy1);
        inst_label->setFont(font);
        inst_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(inst_label, 3, 0, 1, 1);

        date_label = new QLabel(main_widget);
        date_label->setObjectName(QString::fromUtf8("date_label"));
        sizePolicy1.setHeightForWidth(date_label->sizePolicy().hasHeightForWidth());
        date_label->setSizePolicy(sizePolicy1);
        date_label->setFont(font);
        date_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        gridLayout->addWidget(date_label, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        measurements_label = new QLabel(main_widget);
        measurements_label->setObjectName(QString::fromUtf8("measurements_label"));
        sizePolicy1.setHeightForWidth(measurements_label->sizePolicy().hasHeightForWidth());
        measurements_label->setSizePolicy(sizePolicy1);
        measurements_label->setFont(font1);
        measurements_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_7->addWidget(measurements_label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        hc_label = new QLabel(main_widget);
        hc_label->setObjectName(QString::fromUtf8("hc_label"));
        sizePolicy1.setHeightForWidth(hc_label->sizePolicy().hasHeightForWidth());
        hc_label->setSizePolicy(sizePolicy1);
        hc_label->setFont(font);
        hc_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(hc_label, 1, 0, 1, 1);

        Thc_label = new QLabel(main_widget);
        Thc_label->setObjectName(QString::fromUtf8("Thc_label"));
        sizePolicy1.setHeightForWidth(Thc_label->sizePolicy().hasHeightForWidth());
        Thc_label->setSizePolicy(sizePolicy1);
        Thc_label->setFont(font);
        Thc_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Thc_label, 0, 0, 1, 1);

        Tfl_label = new QLabel(main_widget);
        Tfl_label->setObjectName(QString::fromUtf8("Tfl_label"));
        sizePolicy1.setHeightForWidth(Tfl_label->sizePolicy().hasHeightForWidth());
        Tfl_label->setSizePolicy(sizePolicy1);
        Tfl_label->setFont(font);
        Tfl_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Tfl_label, 0, 3, 1, 1);

        Tofd_label = new QLabel(main_widget);
        Tofd_label->setObjectName(QString::fromUtf8("Tofd_label"));
        sizePolicy1.setHeightForWidth(Tofd_label->sizePolicy().hasHeightForWidth());
        Tofd_label->setSizePolicy(sizePolicy1);
        Tofd_label->setFont(font);
        Tofd_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Tofd_label, 0, 2, 1, 1);

        Tbpd_label = new QLabel(main_widget);
        Tbpd_label->setObjectName(QString::fromUtf8("Tbpd_label"));
        sizePolicy1.setHeightForWidth(Tbpd_label->sizePolicy().hasHeightForWidth());
        Tbpd_label->setSizePolicy(sizePolicy1);
        Tbpd_label->setFont(font);
        Tbpd_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Tbpd_label, 0, 1, 1, 1);

        bpd_label = new QLabel(main_widget);
        bpd_label->setObjectName(QString::fromUtf8("bpd_label"));
        sizePolicy1.setHeightForWidth(bpd_label->sizePolicy().hasHeightForWidth());
        bpd_label->setSizePolicy(sizePolicy1);
        bpd_label->setFont(font);
        bpd_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(bpd_label, 1, 1, 1, 1);

        ofd_label = new QLabel(main_widget);
        ofd_label->setObjectName(QString::fromUtf8("ofd_label"));
        sizePolicy1.setHeightForWidth(ofd_label->sizePolicy().hasHeightForWidth());
        ofd_label->setSizePolicy(sizePolicy1);
        ofd_label->setFont(font);
        ofd_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(ofd_label, 1, 2, 1, 1);

        fl_label = new QLabel(main_widget);
        fl_label->setObjectName(QString::fromUtf8("fl_label"));
        sizePolicy1.setHeightForWidth(fl_label->sizePolicy().hasHeightForWidth());
        fl_label->setSizePolicy(sizePolicy1);
        fl_label->setFont(font);
        fl_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(fl_label, 1, 3, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        US_label = new QLabel(main_widget);
        US_label->setObjectName(QString::fromUtf8("US_label"));
        sizePolicy1.setHeightForWidth(US_label->sizePolicy().hasHeightForWidth());
        US_label->setSizePolicy(sizePolicy1);
        US_label->setFont(font1);
        US_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(US_label);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        US1_label = new QLabel(main_widget);
        US1_label->setObjectName(QString::fromUtf8("US1_label"));
        sizePolicy1.setHeightForWidth(US1_label->sizePolicy().hasHeightForWidth());
        US1_label->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(US1_label);

        US2_label = new QLabel(main_widget);
        US2_label->setObjectName(QString::fromUtf8("US2_label"));
        sizePolicy1.setHeightForWidth(US2_label->sizePolicy().hasHeightForWidth());
        US2_label->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(US2_label);

        US3_label = new QLabel(main_widget);
        US3_label->setObjectName(QString::fromUtf8("US3_label"));
        sizePolicy1.setHeightForWidth(US3_label->sizePolicy().hasHeightForWidth());
        US3_label->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(US3_label);

        US4_label = new QLabel(main_widget);
        US4_label->setObjectName(QString::fromUtf8("US4_label"));
        sizePolicy1.setHeightForWidth(US4_label->sizePolicy().hasHeightForWidth());
        US4_label->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(US4_label);


        verticalLayout_8->addLayout(verticalLayout_9);


        verticalLayout_6->addLayout(verticalLayout_8);


        horizontalLayout->addWidget(main_widget);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(back_widget);

        PatientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        PatientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatientWindow->setStatusBar(statusbar);

        retranslateUi(PatientWindow);

        QMetaObject::connectSlotsByName(PatientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PatientWindow)
    {
        PatientWindow->setWindowTitle(QCoreApplication::translate("PatientWindow", "MainWindow", nullptr));
        title_label->setText(QCoreApplication::translate("PatientWindow", "FetalVision", nullptr));
        download_pushButton->setText(QCoreApplication::translate("PatientWindow", "download", nullptr));
        DOB_label->setText(QCoreApplication::translate("PatientWindow", "DOB:", nullptr));
        name_label->setText(QCoreApplication::translate("PatientWindow", "NAME", nullptr));
        ID_label->setText(QCoreApplication::translate("PatientWindow", "PATIENT ID:", nullptr));
        by_label->setText(QCoreApplication::translate("PatientWindow", "PERFORMED BY:", nullptr));
        inst_label->setText(QCoreApplication::translate("PatientWindow", "INSTITUTION: Maternity Hospital", nullptr));
        date_label->setText(QCoreApplication::translate("PatientWindow", "STUDY DATE:", nullptr));
        measurements_label->setText(QCoreApplication::translate("PatientWindow", "FETAL BIOMETRIC MEASUREMENTS", nullptr));
        hc_label->setText(QCoreApplication::translate("PatientWindow", "TextLabel", nullptr));
        Thc_label->setText(QCoreApplication::translate("PatientWindow", "HC", nullptr));
        Tfl_label->setText(QCoreApplication::translate("PatientWindow", "FL", nullptr));
        Tofd_label->setText(QCoreApplication::translate("PatientWindow", "OFD", nullptr));
        Tbpd_label->setText(QCoreApplication::translate("PatientWindow", "BPD", nullptr));
        bpd_label->setText(QCoreApplication::translate("PatientWindow", "TextLabel", nullptr));
        ofd_label->setText(QCoreApplication::translate("PatientWindow", "TextLabel", nullptr));
        fl_label->setText(QCoreApplication::translate("PatientWindow", "TextLabel", nullptr));
        US_label->setText(QCoreApplication::translate("PatientWindow", "ULTRASOUND IMAGES", nullptr));
        US1_label->setText(QCoreApplication::translate("PatientWindow", "IMAGE1", nullptr));
        US2_label->setText(QCoreApplication::translate("PatientWindow", "IMAGE2", nullptr));
        US3_label->setText(QCoreApplication::translate("PatientWindow", "IMAGE3", nullptr));
        US4_label->setText(QCoreApplication::translate("PatientWindow", "IMAGE4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientWindow: public Ui_PatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTWINDOW_H
