/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *welcome_page;
    QVBoxLayout *verticalLayout_8;
    QWidget *welcome_widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QWidget *main_widget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *title;
    QVBoxLayout *verticalLayout_9;
    QLabel *description;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *continueButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *login_page;
    QHBoxLayout *horizontalLayout_5;
    QWidget *login_widget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QWidget *loginSide_widget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *login_title;
    QLabel *login_sub;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QVBoxLayout *verticalLayout_3;
    QLabel *error_message;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginButton;
    QWidget *logo_widget;
    QHBoxLayout *horizontalLayout_7;
    QWidget *img_widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(809, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_9 = new QHBoxLayout(centralwidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        welcome_page = new QWidget();
        welcome_page->setObjectName(QString::fromUtf8("welcome_page"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(welcome_page->sizePolicy().hasHeightForWidth());
        welcome_page->setSizePolicy(sizePolicy1);
        welcome_page->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_8 = new QVBoxLayout(welcome_page);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        welcome_widget = new QWidget(welcome_page);
        welcome_widget->setObjectName(QString::fromUtf8("welcome_widget"));
        sizePolicy1.setHeightForWidth(welcome_widget->sizePolicy().hasHeightForWidth());
        welcome_widget->setSizePolicy(sizePolicy1);
        welcome_widget->setStyleSheet(QString::fromUtf8("QWidget#welcome_widget{\n"
"	background-image: url(:/assets/assets/bg3.jpeg);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(welcome_widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(100, 10, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        main_widget = new QWidget(welcome_widget);
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        sizePolicy.setHeightForWidth(main_widget->sizePolicy().hasHeightForWidth());
        main_widget->setSizePolicy(sizePolicy);
        main_widget->setMaximumSize(QSize(1000, 350));
        main_widget->setLayoutDirection(Qt::LeftToRight);
        main_widget->setStyleSheet(QString::fromUtf8("QWidget#main_widget{\n"
"background-color: rgba(0, 0, 0, 222);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(main_widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        title = new QLabel(main_widget);
        title->setObjectName(QString::fromUtf8("title"));
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setMinimumSize(QSize(0, 0));
        title->setMaximumSize(QSize(16777000, 16777000));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(40);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignCenter';"));
        title->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(title);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetNoConstraint);
        description = new QLabel(main_widget);
        description->setObjectName(QString::fromUtf8("description"));
        sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy);
        description->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        description->setFont(font1);
        description->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignCenter';"));
        description->setWordWrap(true);

        verticalLayout_9->addWidget(description);


        verticalLayout->addLayout(verticalLayout_9);

        verticalSpacer = new QSpacerItem(10, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(-1, 15, -1, 15);
        continueButton = new QPushButton(main_widget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        sizePolicy.setHeightForWidth(continueButton->sizePolicy().hasHeightForWidth());
        continueButton->setSizePolicy(sizePolicy);
        continueButton->setMinimumSize(QSize(150, 30));
        continueButton->setMaximumSize(QSize(150, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Helvetica Neue"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        continueButton->setFont(font2);
        continueButton->setStyleSheet(QString::fromUtf8("border-radius: 1px;\n"
"background-color: rgb(255, 255, 255);\n"
"font: 14pt \"Helvetica Neue\";\n"
"color: rgb(0, 0, 0);\n"
""));

        horizontalLayout_2->addWidget(continueButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_4->addWidget(main_widget);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_8->addWidget(welcome_widget);

        stackedWidget->addWidget(welcome_page);
        login_page = new QWidget();
        login_page->setObjectName(QString::fromUtf8("login_page"));
        horizontalLayout_5 = new QHBoxLayout(login_page);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        login_widget = new QWidget(login_page);
        login_widget->setObjectName(QString::fromUtf8("login_widget"));
        login_widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(login_widget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        loginSide_widget = new QWidget(login_widget);
        loginSide_widget->setObjectName(QString::fromUtf8("loginSide_widget"));
        sizePolicy.setHeightForWidth(loginSide_widget->sizePolicy().hasHeightForWidth());
        loginSide_widget->setSizePolicy(sizePolicy);
        loginSide_widget->setStyleSheet(QString::fromUtf8("QWidget#loginSide_widget{\n"
"background-color: rgb(255, 255, 255)\n"
"}\n"
""));
        horizontalLayout_8 = new QHBoxLayout(loginSide_widget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_5->setContentsMargins(40, 40, 40, 40);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_6->setContentsMargins(-1, -1, -1, 0);
        login_title = new QLabel(loginSide_widget);
        login_title->setObjectName(QString::fromUtf8("login_title"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(login_title->sizePolicy().hasHeightForWidth());
        login_title->setSizePolicy(sizePolicy2);
        login_title->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 50pt \"Times New Roman\";\n"
"qproperty-alignment: 'AlignCenter';"));
        login_title->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(login_title);

        login_sub = new QLabel(loginSide_widget);
        login_sub->setObjectName(QString::fromUtf8("login_sub"));
        sizePolicy2.setHeightForWidth(login_sub->sizePolicy().hasHeightForWidth());
        login_sub->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        login_sub->setFont(font3);
        login_sub->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 20pt \"Times New Roman\";\n"
"qproperty-alignment: 'AlignCenter';\n"
"padding: 0px;"));
        login_sub->setLineWidth(1);
        login_sub->setWordWrap(true);

        verticalLayout_6->addWidget(login_sub);


        verticalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_7->setContentsMargins(-1, 0, -1, 0);
        usernameInput = new QLineEdit(loginSide_widget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(10);
        sizePolicy3.setHeightForWidth(usernameInput->sizePolicy().hasHeightForWidth());
        usernameInput->setSizePolicy(sizePolicy3);
        usernameInput->setMinimumSize(QSize(20, 20));
        usernameInput->setMaximumSize(QSize(16777215, 45));
        usernameInput->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"border: 1px solid rgb(169, 169, 169);\n"
"background-color: white;\n"
"padding-left: 10px;\n"
""));

        verticalLayout_7->addWidget(usernameInput);

        passwordInput = new QLineEdit(loginSide_widget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        sizePolicy3.setHeightForWidth(passwordInput->sizePolicy().hasHeightForWidth());
        passwordInput->setSizePolicy(sizePolicy3);
        passwordInput->setMinimumSize(QSize(20, 20));
        passwordInput->setMaximumSize(QSize(16777215, 45));
        passwordInput->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"border: 1px solid rgb(169, 169, 169);\n"
"background-color: white;\n"
"padding-left: 10px;\n"
""));

        verticalLayout_7->addWidget(passwordInput);


        verticalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        error_message = new QLabel(loginSide_widget);
        error_message->setObjectName(QString::fromUtf8("error_message"));
        sizePolicy2.setHeightForWidth(error_message->sizePolicy().hasHeightForWidth());
        error_message->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(14);
        font4.setBold(true);
        error_message->setFont(font4);
        error_message->setStyleSheet(QString::fromUtf8("color: rgb(255, 38, 0);\n"
"qproperty-alignment: 'AlignCenter';\n"
"padding: 0px;"));
        error_message->setWordWrap(true);

        verticalLayout_3->addWidget(error_message);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, -1, 11);
        loginButton = new QPushButton(loginSide_widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        sizePolicy1.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy1);
        loginButton->setMinimumSize(QSize(150, 40));
        loginButton->setMaximumSize(QSize(100, 20));
        loginButton->setSizeIncrement(QSize(0, 0));
        loginButton->setBaseSize(QSize(0, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Helvetica Neue"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setKerning(true);
        loginButton->setFont(font5);
        loginButton->setLayoutDirection(Qt::LeftToRight);
        loginButton->setStyleSheet(QString::fromUtf8("border-radius: 18px;\n"
"background-color: rgb(0, 0, 0);\n"
"font: 700 12.5pt \"Helvetica Neue\";\n"
"color: rgb(255, 255, 255);\n"
"padding: 0px;"));
        loginButton->setInputMethodHints(Qt::ImhDate);

        horizontalLayout_3->addWidget(loginButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_5);


        horizontalLayout->addWidget(loginSide_widget);

        logo_widget = new QWidget(login_widget);
        logo_widget->setObjectName(QString::fromUtf8("logo_widget"));
        sizePolicy.setHeightForWidth(logo_widget->sizePolicy().hasHeightForWidth());
        logo_widget->setSizePolicy(sizePolicy);
        logo_widget->setStyleSheet(QString::fromUtf8("QWidget#logo_widget {\n"
"   background-color: rgb(30, 30, 30);\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(logo_widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        img_widget = new QWidget(logo_widget);
        img_widget->setObjectName(QString::fromUtf8("img_widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(50);
        sizePolicy4.setHeightForWidth(img_widget->sizePolicy().hasHeightForWidth());
        img_widget->setSizePolicy(sizePolicy4);
        img_widget->setMinimumSize(QSize(0, 0));
        img_widget->setMaximumSize(QSize(16777000, 16777000));
        img_widget->setStyleSheet(QString::fromUtf8("QWidget#img_widget{\n"
"	image: url(:/assets/assets/whiteLogo.png);\n"
"}"));

        horizontalLayout_7->addWidget(img_widget);


        horizontalLayout->addWidget(logo_widget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_5->addWidget(login_widget);

        stackedWidget->addWidget(login_page);

        horizontalLayout_9->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Fetal Vision", nullptr));
        description->setText(QCoreApplication::translate("MainWindow", "An AI-powered tool for sonologists that uses deep learning to segment and measure key fetal biometric parameters from 2D ultrasound images, enhancing prenatal diagnostics and care efficiency.", nullptr));
        continueButton->setText(QCoreApplication::translate("MainWindow", "Click to continue", nullptr));
        login_title->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        login_sub->setText(QCoreApplication::translate("MainWindow", "Sign in into your account", nullptr));
        usernameInput->setText(QString());
        usernameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "User ID", nullptr));
        passwordInput->setText(QString());
        passwordInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        error_message->setText(QString());
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
