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

//����� ���������� ������
class CustomCalculatorThread : public QThread
{
    Q_OBJECT
public:
    CustomCalculatorThread(int num, QProgressBar* indicator, QObject* parent = nullptr);
    ~CustomCalculatorThread();

signals:
    //������ � ���������� ������ �������
    void Finished(int num);
    //������ �� ������������� ��������� ��������� progressBar'a
    void Changed(int num, int percent);

protected:
    //������ ������ ������
    void run() override;

private:
    //����� ������
    int ThreadNum;
    //��������� �� ����������� � ������ progressBar
    QProgressBar* Indicator;
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------