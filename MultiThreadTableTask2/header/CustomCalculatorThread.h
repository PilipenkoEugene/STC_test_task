#include <QWidget>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>
#include <QProgressBar>
#include <qdatetime.h>
//-----------------------------------------------------------------------------------------
#define MAX_PROGRESS_VALUE 100
#define MIN_PROGRESS_VALUE 0
#define MIN_PERCENT_TIME 6000
//-----------------------------------------------------------------------------------------

//Класс кастомного потока
class CustomCalculatorThread : public QThread
{
    Q_OBJECT
public:
    CustomCalculatorThread(int num, QProgressBar* indicator, QObject* parent = nullptr);
    ~CustomCalculatorThread();

signals:
    //Сигнал о завершении работы таймера
    void Finished(int num);
    //Сигнал об необходимости изменения состояния progressBar'a
    void Changed(int num, int percent);

protected:
    //Начала работы потока
    void run() override;

private:
    //Номер потока
    int ThreadNum;
    //Указатель на привязанный к потоку progressBar
    QProgressBar* Indicator;
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------