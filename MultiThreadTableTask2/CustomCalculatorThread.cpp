#include "CustomCalculatorThread.h"
//-----------------------------------------------------------------------------------------

CustomCalculatorThread::CustomCalculatorThread(int num, QProgressBar* indicator, QObject* parent)
    : QThread(parent),
    ThreadNum(num),
    Indicator(indicator)
{
}
//-----------------------------------------------------------------------------------------

CustomCalculatorThread::~CustomCalculatorThread()
{
}
//-----------------------------------------------------------------------------------------

//������ ������ ������
void CustomCalculatorThread::run()
{
    //��������� �������� �� 0 �� 100 ���������
    for (int i = MIN_PROGRESS_VALUE; i < MAX_PROGRESS_VALUE; i++) 
    {
        // C������ ��������� ������ ���������� ��������� �����
        QRandomGenerator randGen; 
        // ������������� ����� ���������� ��������� �����
        randGen.seed(QDateTime::currentMSecsSinceEpoch() + i);
        // ������������� ����������� �� ������ ������������� �����
        int randInt = randGen.bounded(MIN_PERCENT_TIME);
        // ���������� ��������� ����� �� 0 �� 5999 ����
        int pause = qrand() % MIN_PERCENT_TIME; 
        // ������ ����� �� ��������� ����� �����������
        QThread::msleep(randInt); 
        
        // �������� � ������������� ���������� ���������� ��������� � �������
        emit Changed(ThreadNum, i + 1);
    }

    // �������� ������� � ���������� ���������
    emit Finished(ThreadNum);
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------