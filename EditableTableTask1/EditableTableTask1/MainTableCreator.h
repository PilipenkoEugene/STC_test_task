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

    // �������� ����� ����������
    void CreateFilters();
    // ������ �������� ����� ��������� + ������ ������
    QVBoxLayout* CreateFilterBlock(QString description, QWidget& filter_widget);
    // �������� ������� � ������
    void CreateTable();
    // ��������� ��������� ������
    void SetDataSource(QString table_name, QVector<QString>& source_headers);
    // ���������� �������� ���� �������
    void SetTableLook();
    // �������� ����� ������ ���������� ��������
    void CreateButtonLay();
    // ������������� ������� ��������� �� ���������
    void InitPopulationFilter();
    // ���������� ������ ������ ����� ���������
    void ReInitModelQuery();

protected:
    // �������� ����
    QVBoxLayout* Layout = nullptr;

    //������� ���������
    QGroupBox* FilterBox = nullptr;
    QLineEdit* AllRecordsFilter = nullptr;
    QComboBox* PopulationFilter = nullptr;

    // ���� ������ ���������� ��������
    QHBoxLayout* ButtonLayout = nullptr;

    // ������ ���������� ��������
    QPushButton* DeleteButton = nullptr;
    QPushButton* AddButton = nullptr;
    QPushButton* EditButton = nullptr;

    // ������� + ������
    QTableView* TableView = nullptr;
    QSqlQueryModel* TableModel = nullptr;

    // ������������ ������� ������� cities
    QVector<QString> SourceHeaders;

private slots:
    // ��������� ������ �� ���� �������
    void OnAllRecordsFilterChanged(const QString& new_text);
    // ��������� ������� �� ���������
    void OnPopulationFilterChanged(int new_index);
    // ������� �� ������ ���������� ��������
    void OnDeleteButtonClicked();
    void OnEditButtonClicked();
    void OnAddButtonClicked();
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------

// ��������� ������� ��� ���������� ����������� ��������� �� �����
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


