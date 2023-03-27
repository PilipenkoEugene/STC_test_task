#include <qwidget.h>
#include <QVBoxLayout>
#include <QTableView>
#include <qpushbutton.h>
#include <QtSql/qsqltablemodel.h>
#include <QStyledItemDelegate>
#include <QGroupBox>
#include <QComboBox>
#include <qlineedit.h>
//-------------------------------------------------------------------

class MainTableCreator :
    public QWidget
{
    Q_OBJECT

public:
    MainTableCreator(QWidget* parent = nullptr);
    ~MainTableCreator();

    // Создание блока фильтрации
    void CreateFilters();
    // Шаблон создание блока заголовок + виджет фильра
    QVBoxLayout* CreateFilterBlock(QString description, QWidget& filter_widget);
    // Создание таблицы и модели
    void CreateTable();
    // Установка источника данных
    void SetDataSource(QString table_name, QVector<QString>& source_headers);
    // Подготовка внешнего вида таблицы
    void SetTableLook();
    // Создание блока кнопок управления записями
    void CreateButtonLay();
    // Инициализация виджета фильрации по населению
    void InitPopulationFilter();
    // Обновление данных модели после изменения
    void ReInitModelQuery();

protected:
    // Основной слой
    QVBoxLayout* Layout = nullptr;

    //Виджеты фильрации
    QGroupBox* FilterBox = nullptr;
    QLineEdit* AllRecordsFilter = nullptr;
    QComboBox* PopulationFilter = nullptr;

    // Слой кнопок управления записями
    QHBoxLayout* ButtonLayout = nullptr;

    // Кнопки управления записями
    QPushButton* DeleteButton = nullptr;
    QPushButton* AddButton = nullptr;
    QPushButton* EditButton = nullptr;

    // Таблица + модель
    QTableView* TableView = nullptr;
    QSqlQueryModel* TableModel = nullptr;

    // Наименование стобцов таблицы cities
    QVector<QString> SourceHeaders;

private slots:
    // Изменение фильра по всем записям
    void OnAllRecordsFilterChanged(const QString& new_text);
    // Изменение фильтра по населению
    void OnPopulationFilterChanged(int new_index);
    // Нажатие на кнопки управления записями
    void OnDeleteButtonClicked();
    void OnEditButtonClicked();
    void OnAddButtonClicked();
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------

// Кастомный делегат для округления численности населения до тысяч
class NumberDelegate : public QStyledItemDelegate
{
public:
    NumberDelegate();
    ~NumberDelegate();
    QString displayText(const QVariant& value, const QLocale& locale) const override
    {
        uint32_t val = value.toInt();
        uint32_t rounded_value = val / 1000 + (val % 1000 > 499 ? 1 : 0);

        return locale.toString(rounded_value);
    }
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------


