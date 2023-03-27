#include "../header/MultiThreadTableTask2.h"
//-----------------------------------------------------------------------------------------

MultiThreadTableTask2::MultiThreadTableTask2(QWidget* parent)
    : QWidget(parent)
{
    // Создаем таблицу из двух столбцов ["Номер задачи", "Статус"]
    ProgressTable = new QTableWidget();
    ProgressTable->setColumnCount(MAIN_TABLE_COLUMN_COUNT);
    ProgressTable->setHorizontalHeaderLabels({ "Procedure", "Status" });

    // Создаем 50 строк задач с привязанными progressBar'ами для каждой задачи
    for (int i = 0; i < PROCEDURE_COUNT; i++) 
    {
        // Добавляем строку
        ProgressTable->insertRow(i);
        // Устанавливаем название задачи в первую колонку
        ProgressTable->setItem(i, PROCEDURE_COLUMN_NUMBER, new QTableWidgetItem(QString("Procedure %1").arg(i)));
        // Создаем progressBar и инициализируем возможные принимаемые значения
        QProgressBar* indicator = new QProgressBar();
        indicator->setMinimum(MIN_PROGRESS_VALUE);
        indicator->setMaximum(MAX_PROGRESS_VALUE);
        // Устанавливаем созданный progressBar во второй столбец
        ProgressTable->setCellWidget(i, STATUS_COLUMN_NUMBER, indicator);
    }

    //Добавляем таблицу но слой отображения
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(ProgressTable);
    this->setLayout(layout);

    // Запуск расчетов в отдельных потоках
    Calculate();
}
//-----------------------------------------------------------------------------------------

MultiThreadTableTask2::~MultiThreadTableTask2()
{
    //Уничтожаем все созданные потоки
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
    //Создадим пул потоков для эмуляции расчетов
    for (int i = 0; i < PROCEDURE_COUNT; i++) 
    {
        //Получаем указатель на связанный с этой задачей progressBar
        QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(i, 1));
        //Создаем кастомный поток и добавляем его в пул
        CustomCalculatorThread* thread = new CustomCalculatorThread(i, indicator, this);
        ThreadList.append(thread);

        //Связываем сигналы потоков со слотами обработки
        connect(thread, &CustomCalculatorThread::Finished, this, &MultiThreadTableTask2::UpdateTable);
        connect(thread, &CustomCalculatorThread::Changed, this, &MultiThreadTableTask2::UpdateProgressValue);

        //Запускаем поток
        thread->start();
    }
}
//-----------------------------------------------------------------------------------------

void MultiThreadTableTask2::UpdateTable(int num)
{
    //Обновляем значние progresBar'a и выводим отладочное сообщение о завершении выполнения
    //операции
    QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(num, 1));
    indicator->setValue(MAX_PROGRESS_VALUE);
    qDebug() << QString("Procedure %1").arg(num) + " completed!";
}
//-----------------------------------------------------------------------------------------

void MultiThreadTableTask2::UpdateProgressValue(int num, int percent)
{
    //Обновляем значение progressBar'a по сигналу потока
    QProgressBar* indicator = qobject_cast<QProgressBar*>(ProgressTable->cellWidget(num, 1));
    indicator->setValue(percent);
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
