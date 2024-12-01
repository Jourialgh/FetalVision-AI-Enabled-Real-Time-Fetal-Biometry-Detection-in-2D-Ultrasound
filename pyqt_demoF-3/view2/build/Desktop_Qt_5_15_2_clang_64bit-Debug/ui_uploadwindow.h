/********************************************************************************
** Form generated from reading UI file 'uploadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWINDOW_H
#define UI_UPLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *main_container;
    QGridLayout *gridLayout_2;
    QHBoxLayout *HEADER_horizontalLayout;
    QPushButton *menu_pushButton;
    QLabel *logoTitle;
    QWidget *menu_widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *patients_pushButton;
    QLabel *patientsLabel;
    QVBoxLayout *logout_verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *logout_pushButton;
    QLabel *logoutLabel;
    QStackedWidget *stackedWidget;
    QWidget *patients_page;
    QHBoxLayout *horizontalLayout_15;
    QWidget *patients_widget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *patients_label;
    QHBoxLayout *horizontalLayout_28;
    QTableWidget *patientTable;
    QWidget *page1_uploadHC;
    QHBoxLayout *horizontalLayout_12;
    QWidget *uploadHC_widget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *HC_title;
    QVBoxLayout *verticalLayout_11;
    QLabel *HC_description;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *uploadHC_pushButton;
    QHBoxLayout *horizontalLayout_11;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *resetHC_pushButton;
    QPushButton *mHC_pushButton;
    QWidget *page2_measureHC;
    QHBoxLayout *horizontalLayout_13;
    QWidget *measureHC_widget;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *mHC_label1;
    QVBoxLayout *verticalLayout_9;
    QLabel *mHC_label2;
    QLabel *mBPD_label;
    QLabel *mOFD_label;
    QHBoxLayout *horizontalLayout_17;
    QLabel *uploadedHCImage_label;
    QLabel *resultHCImage_label;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveHC_pushButton;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *back_pushButton;
    QPushButton *next_pushButton_2;
    QWidget *page3_uploadFL;
    QHBoxLayout *horizontalLayout_18;
    QWidget *uploadFL_widget;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_13;
    QLabel *FL_title;
    QVBoxLayout *verticalLayout_14;
    QLabel *FL_description;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *uploadFL_pushButton;
    QHBoxLayout *horizontalLayout_23;
    QListWidget *listWidget_2;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *resetFL_pushButton;
    QPushButton *mFL_pushButton;
    QWidget *page4_measureFL;
    QHBoxLayout *horizontalLayout_20;
    QWidget *measureFL_widget;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_15;
    QLabel *mFL_label1;
    QVBoxLayout *verticalLayout_16;
    QLabel *mFL_label2;
    QHBoxLayout *horizontalLayout_27;
    QLabel *FL_inputIMG;
    QLabel *FL_outputIMG;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *saveFL_pushButton;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *pushButton;
    QPushButton *done_pushButton;
    QWidget *last_page;
    QHBoxLayout *horizontalLayout_31;
    QWidget *last_widget;
    QHBoxLayout *horizontalLayout_30;
    QVBoxLayout *verticalLayout_17;
    QWidget *bgImg_widget;
    QVBoxLayout *verticalLayout_22;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_2;
    QLabel *closing_label;
    QHBoxLayout *horizontalLayout_33;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UploadWindow)
    {
        if (UploadWindow->objectName().isEmpty())
            UploadWindow->setObjectName(QString::fromUtf8("UploadWindow"));
        UploadWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UploadWindow->sizePolicy().hasHeightForWidth());
        UploadWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(UploadWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        main_container = new QWidget(centralwidget);
        main_container->setObjectName(QString::fromUtf8("main_container"));
        sizePolicy.setHeightForWidth(main_container->sizePolicy().hasHeightForWidth());
        main_container->setSizePolicy(sizePolicy);
        main_container->setStyleSheet(QString::fromUtf8("QWidget#main_container{\n"
"background-color: rgb(38, 38, 38);\n"
"}"));
        gridLayout_2 = new QGridLayout(main_container);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout_2->setHorizontalSpacing(6);
        HEADER_horizontalLayout = new QHBoxLayout();
        HEADER_horizontalLayout->setObjectName(QString::fromUtf8("HEADER_horizontalLayout"));
        HEADER_horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        menu_pushButton = new QPushButton(main_container);
        menu_pushButton->setObjectName(QString::fromUtf8("menu_pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menu_pushButton->sizePolicy().hasHeightForWidth());
        menu_pushButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        menu_pushButton->setFont(font);
        menu_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: white;\n"
"text-align:left;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/menu-4-xl.png"), QSize(), QIcon::Normal, QIcon::Off);
        menu_pushButton->setIcon(icon);

        HEADER_horizontalLayout->addWidget(menu_pushButton);

        logoTitle = new QLabel(main_container);
        logoTitle->setObjectName(QString::fromUtf8("logoTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(logoTitle->sizePolicy().hasHeightForWidth());
        logoTitle->setSizePolicy(sizePolicy2);
        logoTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Times New Roman\";\n"
"qproperty-alignment: 'AlignCenter';"));

        HEADER_horizontalLayout->addWidget(logoTitle);

        HEADER_horizontalLayout->setStretch(0, 1);
        HEADER_horizontalLayout->setStretch(1, 4);

        gridLayout_2->addLayout(HEADER_horizontalLayout, 0, 0, 1, 2);

        menu_widget = new QWidget(main_container);
        menu_widget->setObjectName(QString::fromUtf8("menu_widget"));
        sizePolicy.setHeightForWidth(menu_widget->sizePolicy().hasHeightForWidth());
        menu_widget->setSizePolicy(sizePolicy);
        menu_widget->setMaximumSize(QSize(150, 16777215));
        menu_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 38, 38);"));
        horizontalLayout_4 = new QHBoxLayout(menu_widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(-1, -1, -1, 400);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(8, -1, 8, -1);
        patients_pushButton = new QPushButton(menu_widget);
        patients_pushButton->setObjectName(QString::fromUtf8("patients_pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(patients_pushButton->sizePolicy().hasHeightForWidth());
        patients_pushButton->setSizePolicy(sizePolicy3);
        patients_pushButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/icons8-group-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        patients_pushButton->setIcon(icon1);
        patients_pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(patients_pushButton);

        patientsLabel = new QLabel(menu_widget);
        patientsLabel->setObjectName(QString::fromUtf8("patientsLabel"));
        sizePolicy3.setHeightForWidth(patientsLabel->sizePolicy().hasHeightForWidth());
        patientsLabel->setSizePolicy(sizePolicy3);
        patientsLabel->setFont(font);
        patientsLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
""));

        horizontalLayout_3->addWidget(patientsLabel);

        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_5);

        logout_verticalLayout = new QVBoxLayout();
        logout_verticalLayout->setObjectName(QString::fromUtf8("logout_verticalLayout"));
        logout_verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(8, -1, 8, -1);
        logout_pushButton = new QPushButton(menu_widget);
        logout_pushButton->setObjectName(QString::fromUtf8("logout_pushButton"));
        sizePolicy3.setHeightForWidth(logout_pushButton->sizePolicy().hasHeightForWidth());
        logout_pushButton->setSizePolicy(sizePolicy3);
        logout_pushButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/icons8-logout-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        logout_pushButton->setIcon(icon2);
        logout_pushButton->setIconSize(QSize(18, 18));

        horizontalLayout_5->addWidget(logout_pushButton);

        logoutLabel = new QLabel(menu_widget);
        logoutLabel->setObjectName(QString::fromUtf8("logoutLabel"));
        sizePolicy3.setHeightForWidth(logoutLabel->sizePolicy().hasHeightForWidth());
        logoutLabel->setSizePolicy(sizePolicy3);
        logoutLabel->setFont(font);
        logoutLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
""));

        horizontalLayout_5->addWidget(logoutLabel);

        horizontalLayout_5->setStretch(1, 3);

        logout_verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(logout_verticalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout_2->addWidget(menu_widget, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(main_container);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        patients_page = new QWidget();
        patients_page->setObjectName(QString::fromUtf8("patients_page"));
        horizontalLayout_15 = new QHBoxLayout(patients_page);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        patients_widget = new QWidget(patients_page);
        patients_widget->setObjectName(QString::fromUtf8("patients_widget"));
        sizePolicy.setHeightForWidth(patients_widget->sizePolicy().hasHeightForWidth());
        patients_widget->setSizePolicy(sizePolicy);
        patients_widget->setStyleSheet(QString::fromUtf8("QWidget#patients_widget{\n"
"background-color: rgb(124, 124, 124);\n"
"}\n"
""));
        horizontalLayout_8 = new QHBoxLayout(patients_widget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        patients_label = new QLabel(patients_widget);
        patients_label->setObjectName(QString::fromUtf8("patients_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        font1.setBold(true);
        patients_label->setFont(font1);
        patients_label->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));

        verticalLayout_4->addWidget(patients_label);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(-1, -1, -1, 0);
        patientTable = new QTableWidget(patients_widget);
        if (patientTable->columnCount() < 3)
            patientTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        patientTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        patientTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        patientTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        patientTable->setObjectName(QString::fromUtf8("patientTable"));
        patientTable->horizontalHeader()->setVisible(true);
        patientTable->horizontalHeader()->setCascadingSectionResizes(false);
        patientTable->horizontalHeader()->setMinimumSectionSize(200);
        patientTable->horizontalHeader()->setDefaultSectionSize(200);
        patientTable->horizontalHeader()->setHighlightSections(true);
        patientTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        patientTable->horizontalHeader()->setStretchLastSection(true);
        patientTable->verticalHeader()->setVisible(true);
        patientTable->verticalHeader()->setCascadingSectionResizes(false);
        patientTable->verticalHeader()->setDefaultSectionSize(30);
        patientTable->verticalHeader()->setHighlightSections(true);
        patientTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        patientTable->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_28->addWidget(patientTable);


        verticalLayout_3->addLayout(horizontalLayout_28);


        horizontalLayout_8->addLayout(verticalLayout_3);


        horizontalLayout_15->addWidget(patients_widget);

        stackedWidget->addWidget(patients_page);
        page1_uploadHC = new QWidget();
        page1_uploadHC->setObjectName(QString::fromUtf8("page1_uploadHC"));
        page1_uploadHC->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_12 = new QHBoxLayout(page1_uploadHC);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        uploadHC_widget = new QWidget(page1_uploadHC);
        uploadHC_widget->setObjectName(QString::fromUtf8("uploadHC_widget"));
        sizePolicy.setHeightForWidth(uploadHC_widget->sizePolicy().hasHeightForWidth());
        uploadHC_widget->setSizePolicy(sizePolicy);
        uploadHC_widget->setStyleSheet(QString::fromUtf8("QWidget#uploadHC_widget{\n"
"background-color: rgb(124, 124, 124);\n"
"}\n"
""));
        horizontalLayout_7 = new QHBoxLayout(uploadHC_widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        HC_title = new QLabel(uploadHC_widget);
        HC_title->setObjectName(QString::fromUtf8("HC_title"));
        sizePolicy2.setHeightForWidth(HC_title->sizePolicy().hasHeightForWidth());
        HC_title->setSizePolicy(sizePolicy2);
        HC_title->setFont(font1);
        HC_title->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));

        verticalLayout_8->addWidget(HC_title);


        verticalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        HC_description = new QLabel(uploadHC_widget);
        HC_description->setObjectName(QString::fromUtf8("HC_description"));
        sizePolicy2.setHeightForWidth(HC_description->sizePolicy().hasHeightForWidth());
        HC_description->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(14);
        HC_description->setFont(font2);
        HC_description->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));
        HC_description->setWordWrap(true);

        verticalLayout_11->addWidget(HC_description);


        verticalLayout_2->addLayout(verticalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        uploadHC_pushButton = new QPushButton(uploadHC_widget);
        uploadHC_pushButton->setObjectName(QString::fromUtf8("uploadHC_pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(uploadHC_pushButton->sizePolicy().hasHeightForWidth());
        uploadHC_pushButton->setSizePolicy(sizePolicy4);
        uploadHC_pushButton->setMinimumSize(QSize(0, 0));
        uploadHC_pushButton->setMaximumSize(QSize(150, 35));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/img2.icons8.com.png"), QSize(), QIcon::Normal, QIcon::Off);
        uploadHC_pushButton->setIcon(icon3);

        horizontalLayout_9->addWidget(uploadHC_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        listWidget = new QListWidget(uploadHC_widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(listWidget);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(8, -1, 8, -1);
        resetHC_pushButton = new QPushButton(uploadHC_widget);
        resetHC_pushButton->setObjectName(QString::fromUtf8("resetHC_pushButton"));

        horizontalLayout_10->addWidget(resetHC_pushButton);

        mHC_pushButton = new QPushButton(uploadHC_widget);
        mHC_pushButton->setObjectName(QString::fromUtf8("mHC_pushButton"));

        horizontalLayout_10->addWidget(mHC_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_7->addLayout(verticalLayout_2);


        horizontalLayout_12->addWidget(uploadHC_widget);

        stackedWidget->addWidget(page1_uploadHC);
        page2_measureHC = new QWidget();
        page2_measureHC->setObjectName(QString::fromUtf8("page2_measureHC"));
        horizontalLayout_13 = new QHBoxLayout(page2_measureHC);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        measureHC_widget = new QWidget(page2_measureHC);
        measureHC_widget->setObjectName(QString::fromUtf8("measureHC_widget"));
        sizePolicy.setHeightForWidth(measureHC_widget->sizePolicy().hasHeightForWidth());
        measureHC_widget->setSizePolicy(sizePolicy);
        measureHC_widget->setStyleSheet(QString::fromUtf8("QWidget#measureHC_widget{\n"
"background-color: rgb(124, 124, 124);\n"
"}\n"
""));
        horizontalLayout_14 = new QHBoxLayout(measureHC_widget);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        mHC_label1 = new QLabel(measureHC_widget);
        mHC_label1->setObjectName(QString::fromUtf8("mHC_label1"));
        mHC_label1->setFont(font1);
        mHC_label1->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));

        verticalLayout_7->addWidget(mHC_label1);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        mHC_label2 = new QLabel(measureHC_widget);
        mHC_label2->setObjectName(QString::fromUtf8("mHC_label2"));
        mHC_label2->setFont(font2);
        mHC_label2->setStyleSheet(QString::fromUtf8(""));
        mHC_label2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(mHC_label2);

        mBPD_label = new QLabel(measureHC_widget);
        mBPD_label->setObjectName(QString::fromUtf8("mBPD_label"));
        mBPD_label->setFont(font2);

        verticalLayout_9->addWidget(mBPD_label);

        mOFD_label = new QLabel(measureHC_widget);
        mOFD_label->setObjectName(QString::fromUtf8("mOFD_label"));
        mOFD_label->setFont(font2);

        verticalLayout_9->addWidget(mOFD_label);


        verticalLayout_6->addLayout(verticalLayout_9);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        uploadedHCImage_label = new QLabel(measureHC_widget);
        uploadedHCImage_label->setObjectName(QString::fromUtf8("uploadedHCImage_label"));

        horizontalLayout_17->addWidget(uploadedHCImage_label);

        resultHCImage_label = new QLabel(measureHC_widget);
        resultHCImage_label->setObjectName(QString::fromUtf8("resultHCImage_label"));

        horizontalLayout_17->addWidget(resultHCImage_label);


        verticalLayout_6->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, -1, 8, -1);
        saveHC_pushButton = new QPushButton(measureHC_widget);
        saveHC_pushButton->setObjectName(QString::fromUtf8("saveHC_pushButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(saveHC_pushButton->sizePolicy().hasHeightForWidth());
        saveHC_pushButton->setSizePolicy(sizePolicy5);
        saveHC_pushButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(saveHC_pushButton);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(1);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        back_pushButton = new QPushButton(measureHC_widget);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));

        horizontalLayout_25->addWidget(back_pushButton);

        next_pushButton_2 = new QPushButton(measureHC_widget);
        next_pushButton_2->setObjectName(QString::fromUtf8("next_pushButton_2"));

        horizontalLayout_25->addWidget(next_pushButton_2);


        horizontalLayout->addLayout(horizontalLayout_25);


        horizontalLayout_16->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(horizontalLayout_16);


        horizontalLayout_14->addLayout(verticalLayout_6);


        horizontalLayout_13->addWidget(measureHC_widget);

        stackedWidget->addWidget(page2_measureHC);
        page3_uploadFL = new QWidget();
        page3_uploadFL->setObjectName(QString::fromUtf8("page3_uploadFL"));
        horizontalLayout_18 = new QHBoxLayout(page3_uploadFL);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        uploadFL_widget = new QWidget(page3_uploadFL);
        uploadFL_widget->setObjectName(QString::fromUtf8("uploadFL_widget"));
        sizePolicy.setHeightForWidth(uploadFL_widget->sizePolicy().hasHeightForWidth());
        uploadFL_widget->setSizePolicy(sizePolicy);
        uploadFL_widget->setStyleSheet(QString::fromUtf8("QWidget#uploadFL_widget{\n"
"background-color: rgb(124, 124, 124);\n"
"}\n"
""));
        horizontalLayout_19 = new QHBoxLayout(uploadFL_widget);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        FL_title = new QLabel(uploadFL_widget);
        FL_title->setObjectName(QString::fromUtf8("FL_title"));
        sizePolicy2.setHeightForWidth(FL_title->sizePolicy().hasHeightForWidth());
        FL_title->setSizePolicy(sizePolicy2);
        FL_title->setFont(font1);
        FL_title->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));

        verticalLayout_13->addWidget(FL_title);


        verticalLayout_10->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        FL_description = new QLabel(uploadFL_widget);
        FL_description->setObjectName(QString::fromUtf8("FL_description"));
        sizePolicy2.setHeightForWidth(FL_description->sizePolicy().hasHeightForWidth());
        FL_description->setSizePolicy(sizePolicy2);
        FL_description->setFont(font2);
        FL_description->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));
        FL_description->setWordWrap(true);

        verticalLayout_14->addWidget(FL_description);


        verticalLayout_10->addLayout(verticalLayout_14);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        uploadFL_pushButton = new QPushButton(uploadFL_widget);
        uploadFL_pushButton->setObjectName(QString::fromUtf8("uploadFL_pushButton"));
        sizePolicy4.setHeightForWidth(uploadFL_pushButton->sizePolicy().hasHeightForWidth());
        uploadFL_pushButton->setSizePolicy(sizePolicy4);
        uploadFL_pushButton->setMaximumSize(QSize(150, 35));
        uploadFL_pushButton->setIcon(icon3);

        horizontalLayout_24->addWidget(uploadFL_pushButton);


        verticalLayout_10->addLayout(horizontalLayout_24);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        listWidget_2 = new QListWidget(uploadFL_widget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        sizePolicy2.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(listWidget_2);


        verticalLayout_10->addLayout(horizontalLayout_23);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(8, -1, 8, -1);
        resetFL_pushButton = new QPushButton(uploadFL_widget);
        resetFL_pushButton->setObjectName(QString::fromUtf8("resetFL_pushButton"));

        horizontalLayout_22->addWidget(resetFL_pushButton);

        mFL_pushButton = new QPushButton(uploadFL_widget);
        mFL_pushButton->setObjectName(QString::fromUtf8("mFL_pushButton"));

        horizontalLayout_22->addWidget(mFL_pushButton);


        verticalLayout_10->addLayout(horizontalLayout_22);


        horizontalLayout_19->addLayout(verticalLayout_10);


        horizontalLayout_18->addWidget(uploadFL_widget);

        stackedWidget->addWidget(page3_uploadFL);
        page4_measureFL = new QWidget();
        page4_measureFL->setObjectName(QString::fromUtf8("page4_measureFL"));
        horizontalLayout_20 = new QHBoxLayout(page4_measureFL);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        measureFL_widget = new QWidget(page4_measureFL);
        measureFL_widget->setObjectName(QString::fromUtf8("measureFL_widget"));
        sizePolicy.setHeightForWidth(measureFL_widget->sizePolicy().hasHeightForWidth());
        measureFL_widget->setSizePolicy(sizePolicy);
        measureFL_widget->setStyleSheet(QString::fromUtf8("QWidget#measureFL_widget{\n"
"background-color: rgb(124, 124, 124);\n"
"}\n"
""));
        horizontalLayout_21 = new QHBoxLayout(measureFL_widget);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        mFL_label1 = new QLabel(measureFL_widget);
        mFL_label1->setObjectName(QString::fromUtf8("mFL_label1"));
        mFL_label1->setFont(font1);
        mFL_label1->setStyleSheet(QString::fromUtf8("qproperty-alignment: 'AlignCenter';"));

        verticalLayout_15->addWidget(mFL_label1);


        verticalLayout_12->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        mFL_label2 = new QLabel(measureFL_widget);
        mFL_label2->setObjectName(QString::fromUtf8("mFL_label2"));
        mFL_label2->setFont(font2);

        verticalLayout_16->addWidget(mFL_label2);


        verticalLayout_12->addLayout(verticalLayout_16);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        FL_inputIMG = new QLabel(measureFL_widget);
        FL_inputIMG->setObjectName(QString::fromUtf8("FL_inputIMG"));

        horizontalLayout_27->addWidget(FL_inputIMG);

        FL_outputIMG = new QLabel(measureFL_widget);
        FL_outputIMG->setObjectName(QString::fromUtf8("FL_outputIMG"));

        horizontalLayout_27->addWidget(FL_outputIMG);


        verticalLayout_12->addLayout(horizontalLayout_27);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(30);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(8, -1, 8, -1);
        saveFL_pushButton = new QPushButton(measureFL_widget);
        saveFL_pushButton->setObjectName(QString::fromUtf8("saveFL_pushButton"));
        sizePolicy5.setHeightForWidth(saveFL_pushButton->sizePolicy().hasHeightForWidth());
        saveFL_pushButton->setSizePolicy(sizePolicy5);
        saveFL_pushButton->setMinimumSize(QSize(0, 0));
        saveFL_pushButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_26->addWidget(saveFL_pushButton);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(1);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        pushButton = new QPushButton(measureFL_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_29->addWidget(pushButton);

        done_pushButton = new QPushButton(measureFL_widget);
        done_pushButton->setObjectName(QString::fromUtf8("done_pushButton"));

        horizontalLayout_29->addWidget(done_pushButton);


        horizontalLayout_26->addLayout(horizontalLayout_29);


        verticalLayout_12->addLayout(horizontalLayout_26);


        horizontalLayout_21->addLayout(verticalLayout_12);


        horizontalLayout_20->addWidget(measureFL_widget);

        stackedWidget->addWidget(page4_measureFL);
        last_page = new QWidget();
        last_page->setObjectName(QString::fromUtf8("last_page"));
        sizePolicy.setHeightForWidth(last_page->sizePolicy().hasHeightForWidth());
        last_page->setSizePolicy(sizePolicy);
        horizontalLayout_31 = new QHBoxLayout(last_page);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        last_widget = new QWidget(last_page);
        last_widget->setObjectName(QString::fromUtf8("last_widget"));
        sizePolicy.setHeightForWidth(last_widget->sizePolicy().hasHeightForWidth());
        last_widget->setSizePolicy(sizePolicy);
        last_widget->setStyleSheet(QString::fromUtf8("QWidget#last_widget{\n"
"	background-color: rgb(24, 24, 24);\n"
"	filter: blur(100px);\n"
"}"));
        horizontalLayout_30 = new QHBoxLayout(last_widget);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(25, 25, 25, 25);
        bgImg_widget = new QWidget(last_widget);
        bgImg_widget->setObjectName(QString::fromUtf8("bgImg_widget"));
        sizePolicy.setHeightForWidth(bgImg_widget->sizePolicy().hasHeightForWidth());
        bgImg_widget->setSizePolicy(sizePolicy);
        bgImg_widget->setStyleSheet(QString::fromUtf8("QWidget#bgImg_widget{\n"
"	image: url(:/assets/assets/blurry_log02.png);\n"
"}"));
        verticalLayout_22 = new QVBoxLayout(bgImg_widget);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_18 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_18->setSpacing(-1);
#endif
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(18, -1, 18, -1);
        closing_label = new QLabel(bgImg_widget);
        closing_label->setObjectName(QString::fromUtf8("closing_label"));
        sizePolicy.setHeightForWidth(closing_label->sizePolicy().hasHeightForWidth());
        closing_label->setSizePolicy(sizePolicy);
        closing_label->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(35);
        font3.setBold(true);
        closing_label->setFont(font3);
        closing_label->setStyleSheet(QString::fromUtf8(""));
        closing_label->setWordWrap(true);

        horizontalLayout_2->addWidget(closing_label);


        verticalLayout_18->addLayout(horizontalLayout_2);


        verticalLayout_22->addLayout(verticalLayout_18);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        pushButton_2 = new QPushButton(bgImg_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy5.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy5);
        pushButton_2->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_33->addWidget(pushButton_2);


        verticalLayout_22->addLayout(horizontalLayout_33);


        verticalLayout_17->addWidget(bgImg_widget);


        horizontalLayout_30->addLayout(verticalLayout_17);


        horizontalLayout_31->addWidget(last_widget);

        stackedWidget->addWidget(last_page);

        gridLayout_2->addWidget(stackedWidget, 1, 1, 1, 1);


        gridLayout->addWidget(main_container, 0, 0, 1, 1);

        UploadWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UploadWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UploadWindow->setStatusBar(statusbar);

        retranslateUi(UploadWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(UploadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UploadWindow)
    {
        UploadWindow->setWindowTitle(QCoreApplication::translate("UploadWindow", "FetalVision", nullptr));
        menu_pushButton->setText(QCoreApplication::translate("UploadWindow", "   MENU", nullptr));
        logoTitle->setText(QCoreApplication::translate("UploadWindow", "FetalVision", nullptr));
        patients_pushButton->setText(QString());
        patientsLabel->setText(QCoreApplication::translate("UploadWindow", "PATIENTS", nullptr));
        logout_pushButton->setText(QString());
        logoutLabel->setText(QCoreApplication::translate("UploadWindow", "LOGOUT", nullptr));
        patients_label->setText(QCoreApplication::translate("UploadWindow", "Patient Managment", nullptr));
        QTableWidgetItem *___qtablewidgetitem = patientTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UploadWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = patientTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UploadWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = patientTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UploadWindow", "DOB", nullptr));
        HC_title->setText(QCoreApplication::translate("UploadWindow", "Upload Image of Fetal's Head", nullptr));
        HC_description->setText(QCoreApplication::translate("UploadWindow", "Please upload an ultrasound image in a supported format (e.g., JPEG, PNG).", nullptr));
        uploadHC_pushButton->setText(QCoreApplication::translate("UploadWindow", "upload", nullptr));
        resetHC_pushButton->setText(QCoreApplication::translate("UploadWindow", "reset", nullptr));
        mHC_pushButton->setText(QCoreApplication::translate("UploadWindow", "measure HC", nullptr));
        mHC_label1->setText(QCoreApplication::translate("UploadWindow", "Measurment Results", nullptr));
        mHC_label2->setText(QCoreApplication::translate("UploadWindow", "Head Circumference (HC): [Measurement]", nullptr));
        mBPD_label->setText(QCoreApplication::translate("UploadWindow", "Biparietal Diameter (BPD): [Measurement]", nullptr));
        mOFD_label->setText(QCoreApplication::translate("UploadWindow", ")ccipitofrontal Diameter (OFD): [Measurement]", nullptr));
        uploadedHCImage_label->setText(QCoreApplication::translate("UploadWindow", "TextLabel", nullptr));
        resultHCImage_label->setText(QCoreApplication::translate("UploadWindow", "TextLabel", nullptr));
        saveHC_pushButton->setText(QCoreApplication::translate("UploadWindow", "save", nullptr));
        back_pushButton->setText(QCoreApplication::translate("UploadWindow", "back", nullptr));
        next_pushButton_2->setText(QCoreApplication::translate("UploadWindow", "next", nullptr));
        FL_title->setText(QCoreApplication::translate("UploadWindow", "Upload Image of Fetal's Femur", nullptr));
        FL_description->setText(QCoreApplication::translate("UploadWindow", "Please upload an ultrasound image in a supported format (e.g., JPEG, PNG).", nullptr));
        uploadFL_pushButton->setText(QCoreApplication::translate("UploadWindow", "upload", nullptr));
        resetFL_pushButton->setText(QCoreApplication::translate("UploadWindow", "reset", nullptr));
        mFL_pushButton->setText(QCoreApplication::translate("UploadWindow", "measure FL", nullptr));
        mFL_label1->setText(QCoreApplication::translate("UploadWindow", "Measurment Results", nullptr));
        mFL_label2->setText(QCoreApplication::translate("UploadWindow", "Femur Length (FL): [Measurement]", nullptr));
        FL_inputIMG->setText(QString());
        FL_outputIMG->setText(QString());
        saveFL_pushButton->setText(QCoreApplication::translate("UploadWindow", "save", nullptr));
        pushButton->setText(QCoreApplication::translate("UploadWindow", "back", nullptr));
        done_pushButton->setText(QCoreApplication::translate("UploadWindow", "done", nullptr));
        closing_label->setText(QCoreApplication::translate("UploadWindow", "The record has been successfully saved to the database...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UploadWindow", "view", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UploadWindow: public Ui_UploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWINDOW_H
