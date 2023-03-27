#pragma once
//-----------------------------------------------------------------------------------------
#include <QtWidgets/QMainWindow>
#include "ui_MultiThreadTableTask2.h"
#include <QWidget>
#include <QDateTime>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>
#include "CustomCalculatorThread.h"
//-----------------------------------------------------------------------------------------
#define MAIN_TABLE_COLUMN_COUNT 2
#define PROCEDURE_COLUMN_NUMBER 0
#define STATUS_COLUMN_NUMBER 1
#define PROCEDURE_COUNT 50
//-----------------------------------------------------------------------------------------

class MultiThreadTableTask2 : public QWidget
{
    Q_OBJECT
public:
    MultiThreadTableTask2(QWidget* parent = nullptr);
    ~MultiThreadTableTask2();

private:
    // Создание и запуск потоков
    void Calculate();

private slots:
    // Слот на сигнал изменения состояния прогресса
    void UpdateProgressValue(int num, int percent);
    // Слот завершения выполнения операций в потоке
    void UpdateTable(int num);

private:
    QTableWidget* ProgressTable;
    QList<CustomCalculatorThread*> ThreadList;
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------