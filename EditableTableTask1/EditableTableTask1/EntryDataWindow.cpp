#include "EntryDataWindow.h"
//-------------------------------------------------------------------

EntryDataWindow::EntryDataWindow(QWidget* parent)
{
	// �������������� �������� ���� � ������
	Layout = new QVBoxLayout(this);
	Layout->addStretch();

	ApplyButton = new QPushButton(this);
	ApplyButton->setText("Apply changes");
	connect(ApplyButton, SIGNAL(clicked()), this, SLOT(OnApplyButtonClicked()));

	CancelButton = new QPushButton(this);
	CancelButton->setText("Cancel");
	connect(CancelButton, SIGNAL(clicked()), this, SLOT(OnCancelButtonClicked()));

	this->setLayout(Layout);
	this->setWindowTitle("Entry managment");

	//�������������� ����
	InitFields();
}
//-------------------------------------------------------------------

EntryDataWindow::~EntryDataWindow()
{
}
//-------------------------------------------------------------------

void EntryDataWindow::SetMode(WorkingStatus mode)
{
	Mode = mode;
}
//-------------------------------------------------------------------

void EntryDataWindow::SetData(QSqlRecord record)
{
	// �������� ������ �� �������, ����������� �������� � ����
	Record = record;
	ParentId = Record.value(COLUMN_PARENT_ID_INDEX).toInt();

	uint32_t type_index = Record.value(COLUMN_TYPE_INDEX).toInt();
	EntyType->setCurrentIndex(type_index != NULL ? type_index : 0);

	Prefix->setText(Record.value(COLUMN_PREFIX_INDEX).toString());
	Name->setText(Record.value(COLUMN_NAME_INDEX).toString());
	NameEng->setText(Record.value(COLUMN_NAME_ENG_INDEX).toString());
	MapPoint->setText(Record.value(COLUMN_MAP_POINT_INDEX).toString());
	LatSpin->setValue(Record.value(COLUMN_LAT_INDEX).toDouble());
	LonSpin->setValue(Record.value(COLUMN_LON_INDEX).toDouble());
	AltSpin->setValue(Record.value(COLUMN_ALT_INDEX).toDouble());
	PopulationSpin->setValue(Record.value(COLUMN_POPULATION_INDEX).toInt());
	Description->setText(Record.value(COLUMN_DESCRIPTION_INDEX).toString());
	Country->setText(Record.value(COLUMN_COUNTRY_INDEX).toString());
}
//-------------------------------------------------------------------

bool EntryDataWindow::ValidateFields()
{
	// ������� �� ����������� ����������� �� ��������,
	// ������� ������� ��������� �������� ����������
	return true;
}
//-------------------------------------------------------------------

QHBoxLayout* EntryDataWindow::CreateParamLay(QString title, QWidget* widget)
{
	//�������� ������� ���� �������������� ���� ������
	QHBoxLayout* param_lay = new QHBoxLayout(this);
	param_lay->addWidget(new QLabel(title), 50);
	param_lay->addWidget(widget, 50);
	return param_lay;
}
//-------------------------------------------------------------------

// ������������� �������� ��� ��������������/�������� ������
void EntryDataWindow::InitFields()
{
	// �������������� ������� � ������������� ��������� ��������
	ParentId = EMPTY_PARENT_ID;

	QSqlQuery q;
	q.prepare("SELECT type_id, type_name FROM " + DATABASE_NAME_TYPES);
	q.exec();

	EntyType = new QComboBox(this);
	while (q.next()) {
		QString type_name = q.value(1).toString();
		EntyType->addItem(q.value(1).toString(), q.value(0).toInt());
	}
	Layout->addLayout(CreateParamLay(COLUMN_TYPE_NAME, EntyType));

	Prefix = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_PREFIX_NAME, Prefix));

	Name = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_NAME_NAME, Name));

	NameEng = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_NAME_ENG_NAME, NameEng));

	MapPoint = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_MAP_POINT_NAME, MapPoint));

	LatSpin = new QDoubleSpinBox();
	LatSpin->setRange(-180.0, 180.0); // ������������� �������� �������� 
	LatSpin->setDecimals(6);
	Layout->addLayout(CreateParamLay(COLUMN_LAT_NAME, LatSpin));

	LonSpin = new QDoubleSpinBox();
	LonSpin->setRange(-180.0, 180.0); // ������������� �������� �������� 
	LonSpin->setDecimals(6);
	Layout->addLayout(CreateParamLay(COLUMN_LON_NAME, LonSpin));

	AltSpin = new QDoubleSpinBox();
	AltSpin->setDecimals(6);
	Layout->addLayout(CreateParamLay(COLUMN_ALT_NAME, AltSpin));

	PopulationSpin = new QSpinBox();
	PopulationSpin->setMinimum(0);
	PopulationSpin->setMaximum(INT_MAX);
	Layout->addLayout(CreateParamLay(COLUMN_POPULATION_NAME, PopulationSpin));

	Description = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_DESCRIPTION_NAME, Description));

	Country = new QLineEdit(this);
	Layout->addLayout(CreateParamLay(COLUMN_COUNTRY_NAME, Country));

	QHBoxLayout* button_lay = new QHBoxLayout(this);
	button_lay->addWidget(ApplyButton, 50);
	button_lay->addWidget(CancelButton, 50);

	Layout->addLayout(button_lay);
}
//-------------------------------------------------------------------

void EntryDataWindow::OnApplyButtonClicked()
{
	// ������ ��������� �����
	if (ValidateFields())
	{
		// ��� ������� �������� ����� ������ ��������� sql-������ INSERT INTO � ��������� ���� ��������
		if (Mode == WorkingStatus::Addition)
		{
			QSqlQuery q("INSERT INTO " + DATABASE_NAME_CITIES + " (" +
				COLUMN_PARENT_ID_NAME + ',' +
				COLUMN_TYPE_NAME + ',' +
				COLUMN_PREFIX_NAME + ',' +
				COLUMN_NAME_NAME + ',' +
				COLUMN_NAME_ENG_NAME + ',' +
				COLUMN_MAP_POINT_NAME + ',' +
				COLUMN_LAT_NAME + ',' +
				COLUMN_LON_NAME + ',' +
				COLUMN_ALT_NAME + ',' +
				COLUMN_POPULATION_NAME + ',' +
				COLUMN_DESCRIPTION_NAME + ',' +
				COLUMN_COUNTRY_NAME +
				") VALUES (" +
				QString::number(ParentId) + ',' +
				"'" + EntyType->currentData().toString() + "', " +
				"'" + Prefix->text() + "', " +
				"'" + Name->text() + "', " +
				"'" + NameEng->text() + "', " +
				"'" + MapPoint->text() + "', " +
				QString::number(LatSpin->value()) + ", " +
				QString::number(LonSpin->value()) + ", " +
				QString::number(AltSpin->value()) + ", " +
				QString::number(PopulationSpin->value()) + ", " +
				"'" + Description->text() + "', " +
				"'" + Country->text() + "');"
			);
		}
		// ��� ������� ������������ ��������� sql-������ UPDATE SET � ������ ����������
		else if (Mode == WorkingStatus::Edit)
		{
			QSqlQuery q("UPDATE " + DATABASE_NAME_CITIES + " SET " +
				COLUMN_PARENT_ID_NAME + "=" + QString::number(ParentId) + ',' +
				COLUMN_TYPE_NAME + "=" + "'" + EntyType->currentData().toString() + "'" + ',' +
				COLUMN_PREFIX_NAME + "=" + "'" + Prefix->text() + "'" + ',' +
				COLUMN_NAME_NAME + "=" + "'" + Name->text() + "'" + ',' +
				COLUMN_NAME_ENG_NAME + "=" + "'" + NameEng->text() + "'" + ',' +
				COLUMN_MAP_POINT_NAME + "=" + "'" + MapPoint->text() + "'" + ',' +
				COLUMN_LAT_NAME + "=" + QString::number(LatSpin->value()) + ',' +
				COLUMN_LON_NAME + "=" + QString::number(LonSpin->value()) + ',' +
				COLUMN_ALT_NAME + "=" + QString::number(AltSpin->value()) + ',' +
				COLUMN_POPULATION_NAME + "=" + QString::number(PopulationSpin->value()) + ',' +
				COLUMN_DESCRIPTION_NAME + "=" + "'" + Description->text() + "'" + ',' +
				COLUMN_COUNTRY_NAME + "=" + "'" + Country->text() + "'" +
				" WHERE " +
				COLUMN_ID_NAME + "=" + Record.value(COLUMN_ID_NAME).toString() + ';'
			);
			q.exec();
		}
	}

	// ��������� ���� 
	this->accept();
}
//-------------------------------------------------------------------

void EntryDataWindow::OnCancelButtonClicked()
{
	// ��� ��� ������� ���������� �� ����, ������ ��������� ����
	this->reject();
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
