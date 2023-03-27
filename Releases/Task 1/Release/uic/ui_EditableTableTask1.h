/********************************************************************************
** Form generated from reading UI file 'EditableTableTask1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITABLETABLETASK1_H
#define UI_EDITABLETABLETASK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditableTableTask1Class
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *EditableTableTask1Class)
    {
        if (EditableTableTask1Class->objectName().isEmpty())
            EditableTableTask1Class->setObjectName(QString::fromUtf8("EditableTableTask1Class"));
        EditableTableTask1Class->resize(600, 400);
        centralWidget = new QWidget(EditableTableTask1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EditableTableTask1Class->setCentralWidget(centralWidget);

        retranslateUi(EditableTableTask1Class);

        QMetaObject::connectSlotsByName(EditableTableTask1Class);
    } // setupUi

    void retranslateUi(QMainWindow *EditableTableTask1Class)
    {
        EditableTableTask1Class->setWindowTitle(QCoreApplication::translate("EditableTableTask1Class", "EditableTableTask1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditableTableTask1Class: public Ui_EditableTableTask1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITABLETABLETASK1_H
