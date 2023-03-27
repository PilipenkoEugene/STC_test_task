#include "../header/EditableTableTask1.h"
#include "../header/MainTableCreator.h"
//-------------------------------------------------------------------

EditableTableTask1::EditableTableTask1(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumHeight(700);
    this->setMinimumWidth(900);

    // Инициализируем базу данных
    if (!InitDatabase())
    {
        QMessageBox::critical(this, "Database loading error", "Check the integrity of the database!");
    }
    
    // Инициализируем основной слой
    InitMainLayout();
}
//-------------------------------------------------------------------

EditableTableTask1::~EditableTableTask1()
{
}
//-------------------------------------------------------------------

void EditableTableTask1::InitMainLayout()
{
    Layout->addStretch();

    // Инициализируем основной виджет
    MainTableCreator* CentralWidget = nullptr;

    CentralWidget = new MainTableCreator(this);
    // Создание блока фильтров
    CentralWidget->CreateFilters();
    // Создание таблицы
    CentralWidget->CreateTable();
    // Создание слоя кнопок
    CentralWidget->CreateButtonLay();
    // Указание источника данных
    CentralWidget->SetDataSource(DATABASE_NAME_PATH, SourceHeaders);

    // Установка основного виджета
    setCentralWidget(CentralWidget);
}
//-------------------------------------------------------------------

bool EditableTableTask1::InitDatabase()
{
    // Создаем объект БД и инициализируем путь до БД
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QCoreApplication::applicationDirPath() + DATABASE_NAME_PATH;

    // Проверяем существование файла БД
    if (!QFile(db_path).exists())
    {
        qDebug() << "DB file doesn't exist!";
        return false;
    }

    // Инициализируем объект БД и набор хедеров
    DataBase.setDatabaseName(db_path);

    SourceHeaders.push_back(COLUMN_ID_NAME);
    SourceHeaders.push_back(COLUMN_PARENT_ID_NAME);
    SourceHeaders.push_back(COLUMN_TYPE_NAME);
    SourceHeaders.push_back(COLUMN_PREFIX_NAME);
    SourceHeaders.push_back(COLUMN_NAME_NAME);
    SourceHeaders.push_back(COLUMN_NAME_ENG_NAME);
    SourceHeaders.push_back(COLUMN_MAP_POINT_NAME);
    SourceHeaders.push_back(COLUMN_LAT_NAME);
    SourceHeaders.push_back(COLUMN_LON_NAME);
    SourceHeaders.push_back(COLUMN_ALT_NAME);
    SourceHeaders.push_back(COLUMN_POPULATION_NAME);
    SourceHeaders.push_back(COLUMN_DESCRIPTION_NAME);
    SourceHeaders.push_back(COLUMN_COUNTRY_NAME);
    
    // Пытаемся открыть БД
    return DataBase.open();
}
//-------------------------------------------------------------------
