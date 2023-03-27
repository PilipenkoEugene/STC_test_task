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

//Начала работы потока
void CustomCalculatorThread::run()
{
    //Имитируем прогресс от 0 до 100 процентов
    for (int i = MIN_PROGRESS_VALUE; i < MAX_PROGRESS_VALUE; i++) 
    {
        // Cоздаем экземпляр класса генератора случайных чисел
        QRandomGenerator randGen; 
        // Устанавливаем зерно генератора случайных чисел
        randGen.seed(QDateTime::currentMSecsSinceEpoch() + i);
        // Устанавливаем ограничение на размер генерируемого числа
        int randInt = randGen.bounded(MIN_PERCENT_TIME);
        // Генерируем случайное число от 0 до 5999 мсек
        int pause = qrand() % MIN_PERCENT_TIME; 
        // Делаем паузу на указанное число миллисекунд
        QThread::msleep(randInt); 
        
        // Сообщаем о необходимости обновления индикатора состояния в таблице
        emit Changed(ThreadNum, i + 1);
    }

    // Отправка сигнала о завершении процедуры
    emit Finished(ThreadNum);
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------