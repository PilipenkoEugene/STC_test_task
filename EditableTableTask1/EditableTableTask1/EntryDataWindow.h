#include "EditableTableTask1.h"
//-------------------------------------------------------------------

// Класс окна редактирования/добавления записи
class EntryDataWindow :
    public QDialog
{
    Q_OBJECT

public:
    EntryDataWindow(QWidget* parent = nullptr);
    ~EntryDataWindow();

    // Режим, в котором работает окно
    enum class WorkingStatus
    {
        Addition,
        Edit
    };

    // Инициализация полей
    void InitFields();
    // Установка режима работы окна
    void SetMode(WorkingStatus mode);
    // Установка записи, с которой выполняется работа
    void SetData(QSqlRecord record = QSqlRecord());
    // Валидация полей перед выполнением транзакции
    bool ValidateFields();
    //Слой параметров
    QHBoxLayout* CreateParamLay(QString title, QWidget* widget);

private:
    // Основной слой окна
    QVBoxLayout* Layout = nullptr;
    // Кнопка применения изменений
    QPushButton* ApplyButton = nullptr;
    // Кнопка отмены
    QPushButton* CancelButton = nullptr;
    // Режим работы окна
    WorkingStatus Mode;

    // Редактируемая запись
    QSqlRecord Record;

    // Блок полей таблицы cities
    uint32_t ParentId;
    QComboBox* EntyType;
    QLineEdit* Prefix;
    QLineEdit* Name;
    QLineEdit* NameEng;
    QLineEdit* MapPoint;
    QDoubleSpinBox* LatSpin;
    QDoubleSpinBox* LonSpin;
    QDoubleSpinBox* AltSpin;
    QSpinBox* PopulationSpin;
    QLineEdit* Description;
    QLineEdit* Country;

public slots:
    // Слот применения изменений
    void OnApplyButtonClicked();
    // Слот отмены 
    void OnCancelButtonClicked();
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------

