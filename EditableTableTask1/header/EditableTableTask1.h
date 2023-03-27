#include <QtWidgets/QMainWindow>
#include "ui_EditableTableTask1.h"
#include <QtSql/qsql.h>
#include <QtSql/qsqldatabase.h>
#include <qdebug.h>
#include <qlayout.h>
#include <qwidget.h>
#include <QVBoxLayout>
#include <QTableView>
#include <qpushbutton.h>
#include <QtSql/qsqltablemodel.h>
#include <QStyledItemDelegate>
#include <QGroupBox>
#include <QComboBox>
#include <qlineedit.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <QFile>
#include <qlabel.h>
#include <qdialog.h>
#include <qvariant.h>
#include <QDoubleSpinBox>
//-------------------------------------------------------------------
#define DATABASE_NAME_PATH       QString("/cities.db3")
#define DATABASE_NAME_CITIES     QString("cities")
#define DATABASE_NAME_TYPES      QString("types")
#define COLUMN_COUNT_CITIES      13
#define COLUMN_ID_INDEX          0
#define COLUMN_PARENT_ID_INDEX   1
#define COLUMN_TYPE_INDEX        2
#define COLUMN_PREFIX_INDEX      3
#define COLUMN_NAME_INDEX        4
#define COLUMN_NAME_ENG_INDEX    5
#define COLUMN_MAP_POINT_INDEX   6
#define COLUMN_LAT_INDEX         7
#define COLUMN_LON_INDEX         8
#define COLUMN_ALT_INDEX         9
#define COLUMN_POPULATION_INDEX  10
#define COLUMN_DESCRIPTION_INDEX 11
#define COLUMN_COUNTRY_INDEX     12
#define COLUMN_ID_NAME          QString("id")
#define COLUMN_PARENT_ID_NAME   QString("parent_id")
#define COLUMN_TYPE_NAME        QString("type")
#define COLUMN_PREFIX_NAME      QString("prefix")
#define COLUMN_NAME_NAME        QString("name")
#define COLUMN_NAME_ENG_NAME    QString("name_eng")
#define COLUMN_MAP_POINT_NAME   QString("map_point")
#define COLUMN_LAT_NAME         QString("lat")
#define COLUMN_LON_NAME         QString("lon")
#define COLUMN_ALT_NAME         QString("alt")
#define COLUMN_POPULATION_NAME  QString("population")
#define COLUMN_DESCRIPTION_NAME QString("description")
#define COLUMN_COUNTRY_NAME     QString("country")
#define EMPTY_PARENT_ID         0
//-------------------------------------------------------------------

class EditableTableTask1 : public QMainWindow
{
    Q_OBJECT

public:
    EditableTableTask1(QWidget *parent = nullptr);
    ~EditableTableTask1();

    // База данных
    QSqlDatabase DataBase;
    // Основной слой окна
    QVBoxLayout* Layout = new QVBoxLayout(this);
    // Список названий столбцов таблицы
    QVector<QString> SourceHeaders;

private:
    Ui::EditableTableTask1Class ui;

    // Инициализация centralWidget'a
    void InitMainLayout();
    // Инициализация базы данных
    bool InitDatabase();
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
