#include "../header/MultiThreadTableTask2.h"
//-----------------------------------------------------------------------------------------

MultiThreadTableTask2::MultiThreadTableTask2(QWidget* parent)
    : QWidget(parent)
{
    // ������� ������� �� ���� �������� ["����� ������", "������"]
    ProgressTable = new QTableWidget();
    ProgressTable->setColumnCount(MAIN_TABLE_COLUMN_COUNT);
    ProgressTable->setHorizontalHeaderLabels({ "Procedure", "Status" });

    // ������� 50 ����� ����� � ������������ progressBar'��� ��� ������ ������
    for (int i = 0; i < PROCEDURE_COUNT; i++) 
    {
        // ��������� ������
        ProgressTable->insertRow(i);
        // ������������� �������� ������ � ������ �������
        ProgressTable->setItem(i, PROCEDURE_COLUMN_NUMBER, new QTableWidgetItem(QString("Procedure %1").arg(i)));
        // ������� progressBar � �������������� ��������� ����������� ��������
        QProgressBar* indicator = new QProgressBar();
        indicator->setMinimum(MIN_PROGRESS_VALUE);
        indicator->setMaximum(MAX_PROGRESS_VALUE);
        // ������������� ��������� progressBar �� ������ �������
        ProgressTable->setCellWidget(i, STATUS_COLUMN_NUMBER, indicator);
    }

    //��������� ������� �� ���� �����������
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(ProgressTable);
    this->setLayout(layout);

    // ������ �������� � ��������� �������
    Calculate();
}
//-----------------------------------------------------------------------------------------

MultiThreadTableTask2::~MultiThreadTableTask2()
{
    //���������� ��� ��������� ������
    for (CustomCalculatorThread* thread : ThreadList) 
    {
        thread->terminate();
        thread->wait();
        delete thread;
    }
}
//-----------------------------------------------------------------------------------------

void MultiThreadTableTask2::Calculate()
{
    //�������� ��� ������� ��� �������� ��������
    for (int i = 0; i < PROCEDURE_COUNT; i++) 
    {
        //�������� ��������� �� ��������� � ���� ������� progressBar
        QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(i, 1));
        //������� ��������� ����� � ��������� ��� � ���
        CustomCalculatorThread* thread = new CustomCalculatorThread(i, indicator, this);
        ThreadList.append(thread);

        //��������� ������� ������� �� ������� ���������
        connect(thread, &CustomCalculatorThread::Finished, this, &MultiThreadTableTask2::UpdateTable);
        connect(thread, &CustomCalculatorThread::Changed, this, &MultiThreadTableTask2::UpdateProgressValue);

        //��������� �����
        thread->start();
    }
}
//-----------------------------------------------------------------------------------------

void MultiThreadTableTask2::UpdateTable(int num)
{
    //��������� ������� progresBar'a � ������� ���������� ��������� � ���������� ����������
    //��������
    QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(num, 1));
    indicator->setValue(MAX_PROGRESS_VALUE);
    qDebug() << QString("Procedure %1").arg(num) + " completed!";
}
//-----------------------------------------------------------------------------------------

void MultiThreadTableTask2::UpdateProgressValue(int num, int percent)
{
    //��������� �������� progressBar'a �� ������� ������
    QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(num, 1));
    indicator->setValue(percent);
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
