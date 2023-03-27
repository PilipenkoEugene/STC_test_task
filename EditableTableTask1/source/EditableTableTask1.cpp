#include "../header/EditableTableTask1.h"
#include "../header/MainTableCreator.h"
//-------------------------------------------------------------------

EditableTableTask1::EditableTableTask1(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumHeight(700);
    this->setMinimumWidth(900);

    // �������������� ���� ������
    if (!InitDatabase())
    {
        QMessageBox::critical(this, "Database loading error", "Check the integrity of the database!");
    }
    
    // �������������� �������� ����
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

    // �������������� �������� ������
    MainTableCreator* CentralWidget = nullptr;

    CentralWidget = new MainTableCreator(this);
    // �������� ����� ��������
    CentralWidget->CreateFilters();
    // �������� �������
    CentralWidget->CreateTable();
    // �������� ���� ������
    CentralWidget->CreateButtonLay();
    // �������� ��������� ������
    CentralWidget->SetDataSource(DATABASE_NAME_PATH, SourceHeaders);

    // ��������� ��������� �������
    setCentralWidget(CentralWidget);
}
//-------------------------------------------------------------------

bool EditableTableTask1::InitDatabase()
{
    // ������� ������ �� � �������������� ���� �� ��
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString db_path = QCoreApplication::applicationDirPath() + DATABASE_NAME_PATH;

    // ��������� ������������� ����� ��
    if (!QFile(db_path).exists())
    {
        qDebug() << "DB file doesn't exist!";
        return false;
    }

    // �������������� ������ �� � ����� �������
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
    
    // �������� ������� ��
    return DataBase.open();
}
//-------------------------------------------------------------------
