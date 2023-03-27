/********************************************************************************
** Form generated from reading UI file 'MultiThreadTableTask2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTITHREADTABLETASK2_H
#define UI_MULTITHREADTABLETASK2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiThreadTableTask2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MultiThreadTableTask2Class)
    {
        if (MultiThreadTableTask2Class->objectName().isEmpty())
            MultiThreadTableTask2Class->setObjectName(QString::fromUtf8("MultiThreadTableTask2Class"));
        MultiThreadTableTask2Class->resize(600, 400);
        menuBar = new QMenuBar(MultiThreadTableTask2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MultiThreadTableTask2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MultiThreadTableTask2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MultiThreadTableTask2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(MultiThreadTableTask2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MultiThreadTableTask2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MultiThreadTableTask2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MultiThreadTableTask2Class->setStatusBar(statusBar);

        retranslateUi(MultiThreadTableTask2Class);

        QMetaObject::connectSlotsByName(MultiThreadTableTask2Class);
    } // setupUi

    void retranslateUi(QMainWindow *MultiThreadTableTask2Class)
    {
        MultiThreadTableTask2Class->setWindowTitle(QCoreApplication::translate("MultiThreadTableTask2Class", "MultiThreadTableTask2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultiThreadTableTask2Class: public Ui_MultiThreadTableTask2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTITHREADTABLETASK2_H
