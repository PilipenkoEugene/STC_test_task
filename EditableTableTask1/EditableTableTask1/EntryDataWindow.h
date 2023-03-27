#include "EditableTableTask1.h"
//-------------------------------------------------------------------

// ����� ���� ��������������/���������� ������
class EntryDataWindow :
    public QDialog
{
    Q_OBJECT

public:
    EntryDataWindow(QWidget* parent = nullptr);
    ~EntryDataWindow();

    // �����, � ������� �������� ����
    enum class WorkingStatus
    {
        Addition,
        Edit
    };

    // ������������� �����
    void InitFields();
    // ��������� ������ ������ ����
    void SetMode(WorkingStatus mode);
    // ��������� ������, � ������� ����������� ������
    void SetData(QSqlRecord record = QSqlRecord());
    // ��������� ����� ����� ����������� ����������
    bool ValidateFields();
    //���� ����������
    QHBoxLayout* CreateParamLay(QString title, QWidget* widget);

private:
    // �������� ���� ����
    QVBoxLayout* Layout = nullptr;
    // ������ ���������� ���������
    QPushButton* ApplyButton = nullptr;
    // ������ ������
    QPushButton* CancelButton = nullptr;
    // ����� ������ ����
    WorkingStatus Mode;

    // ������������� ������
    QSqlRecord Record;

    // ���� ����� ������� cities
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
    // ���� ���������� ���������
    void OnApplyButtonClicked();
    // ���� ������ 
    void OnCancelButtonClicked();
};
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------

