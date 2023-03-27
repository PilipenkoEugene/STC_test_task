#include "../header/MainTableCreator.h"
#include "../header/EntryDataWindow.h"
//-------------------------------------------------------------------

MainTableCreator::MainTableCreator(QWidget* parent)
{
	Layout = new QVBoxLayout(this);
	this->setLayout(Layout);
}
//-------------------------------------------------------------------

MainTableCreator::~MainTableCreator()
{
}
//-------------------------------------------------------------------

void MainTableCreator::CreateFilters()
{
	// �������� ���� � ������� ������
	QHBoxLayout* filter_layout = new QHBoxLayout(this);
	FilterBox = new QGroupBox(this);
	FilterBox->setTitle("Filtration Block");

	// ������������� ������� ��������� �� ���� �������
	AllRecordsFilter = new QLineEdit(this);
	AllRecordsFilter->setPlaceholderText("The database entry must include this text");
	connect(AllRecordsFilter, SIGNAL(textEdited(const QString&)), this, SLOT(OnAllRecordsFilterChanged(const QString&)));

	// ������������� ������� ���������� �� ���������
	PopulationFilter = new QComboBox(this);
	// ������������� ������ ��������� ���������� �� ���������
	InitPopulationFilter();
	connect(PopulationFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(OnPopulationFilterChanged(int)));

	FilterBox->setLayout(filter_layout);
	filter_layout->addLayout(CreateFilterBlock("Entry include", *AllRecordsFilter), 35);
	filter_layout->addLayout(CreateFilterBlock("Population", *PopulationFilter), 15);
	filter_layout->addWidget(new QWidget(this), 50);

	Layout->addWidget(FilterBox);
}
//-------------------------------------------------------------------

// ��������� �������� ���� ���������+������ ���������
QVBoxLayout* MainTableCreator::CreateFilterBlock(QString description, QWidget& filter_widget)
{
	QVBoxLayout* filter_layout = new QVBoxLayout(this);

	filter_layout->addWidget(new QLabel(description, this));
	filter_layout->addWidget(&filter_widget);

	return filter_layout;
}
//-------------------------------------------------------------------

// ������������� ������� � ������ + ���������� �� ����
void MainTableCreator::CreateTable()
{
	TableView = new QTableView(this);
	TableModel = new QSqlQueryModel(this);

	TableView->setModel(TableModel);

	Layout->addWidget(TableView);
}
//-------------------------------------------------------------------

void MainTableCreator::SetDataSource(QString table_name, QVector<QString>& source_headers)
{
	// ������� ������� � ��������� �� ���������� � ��������� ����������
	TableModel->setQuery(QString("SELECT * FROM ") + DATABASE_NAME_CITIES);

	uint32_t col_count = TableModel->columnCount();

	if (col_count != source_headers.size())
	{
		QMessageBox::critical(this, "Data source error", "The structure of the table has changed. Check the integrity of the database!");
	}
	else
	{
		// ������� ��������� ����������� �������
		SourceHeaders = source_headers;

		for (uint32_t i = 0; i < TableModel->columnCount(); i++)
		{
			TableModel->setHeaderData(i, Qt::Horizontal, source_headers[i]);
		}

		// �������� ������� ��� ������� � �����������
		SetTableLook();
	}
}
//-------------------------------------------------------------------

void MainTableCreator::SetTableLook()
{
	// ������������� ������� ��� ������� ���������, ����������� ����������
	NumberDelegate* delegate = new NumberDelegate();
	TableView->setItemDelegateForColumn(COLUMN_POPULATION_INDEX, delegate);

	// �������� �������� �������
	TableView->setColumnHidden(COLUMN_ID_INDEX, true);
	TableView->setColumnHidden(COLUMN_PARENT_ID_INDEX, true);
	TableView->setColumnHidden(COLUMN_TYPE_INDEX, true);
	TableView->setColumnHidden(COLUMN_NAME_ENG_INDEX, true);
	TableView->setColumnHidden(COLUMN_ALT_INDEX, true);
}
//-------------------------------------------------------------------

void MainTableCreator::CreateButtonLay()
{
	// ������� ���� ������ ���������� �������� � �������
	ButtonLayout = new QHBoxLayout(this);

	DeleteButton = new QPushButton(this);
	DeleteButton->setText("Delete");
	connect(DeleteButton, SIGNAL(clicked()), this, SLOT(OnDeleteButtonClicked()));

	EditButton = new QPushButton(this);
	EditButton->setText("Edit");
	connect(EditButton, SIGNAL(clicked()), this, SLOT(OnEditButtonClicked()));

	AddButton = new QPushButton(this);
	AddButton->setText("Add");
	connect(AddButton, SIGNAL(clicked()), this, SLOT(OnAddButtonClicked()));

	ButtonLayout->addWidget(DeleteButton, 15);
	ButtonLayout->addWidget(AddButton, 15);
	ButtonLayout->addWidget(EditButton, 15);
	ButtonLayout->addWidget(new QWidget(this), 55);

	Layout->addLayout(ButtonLayout);
}
//-------------------------------------------------------------------

void MainTableCreator::InitPopulationFilter()
{
	// ��������� ������� �� ��������� (magic numbers <3)
	PopulationFilter->addItem("Ignore", 0);
	PopulationFilter->addItem("From 1 thousand", 1000);
	PopulationFilter->addItem("From 10 thousand", 10000);
	PopulationFilter->addItem("From 25 thousand", 25000);
	PopulationFilter->addItem("From 50 thousand", 50000);
	PopulationFilter->addItem("From 100 thousand", 100000);
	PopulationFilter->addItem("From 250 thousand", 250000);
	PopulationFilter->addItem("From 500 thousand", 500000);
	PopulationFilter->addItem("From 1 million", 1000000);
	PopulationFilter->addItem("From 2 million", 2000000);

	PopulationFilter->setCurrentIndex(0);
}
//-------------------------------------------------------------------

void MainTableCreator::ReInitModelQuery()
{
	// ������������������ ������ � ������ � ������ ��������
	QString filter = QString("SELECT * FROM ") + DATABASE_NAME_CITIES + " WHERE(";

	for (int i = 0; i < SourceHeaders.size(); ++i) {
		filter += QString("%1 LIKE '%%2%' OR ").arg(SourceHeaders[i]).arg(AllRecordsFilter->text());
	}
	filter.chop(4);
	filter += ')';

	if (PopulationFilter->currentIndex() != 0)
	{
		filter += QString("AND ") + COLUMN_POPULATION_NAME + " >= " + QString::number(PopulationFilter->currentData().toInt());
	}

	TableModel->setQuery(filter);
	SetTableLook();
	TableView->setModel(TableModel);
}
//-------------------------------------------------------------------

void MainTableCreator::OnAllRecordsFilterChanged(const QString& new_text)
{
	// ��������� ����������������� ��� ������� ���������
	ReInitModelQuery();
}
//-------------------------------------------------------------------

void MainTableCreator::OnPopulationFilterChanged(int new_index)
{
	// ��������� ����������������� ��� ������� ���������
	ReInitModelQuery();
}
//-------------------------------------------------------------------

void MainTableCreator::OnDeleteButtonClicked()
{
	// �������� ������ ��������� ������ � ���������, ��� ������ ������ �������
	int row = TableView->currentIndex().row();
	if (row == -1)
		return;

	// �������� id ��������� ������
	QString id = TableModel->data(TableModel->index(row, 0)).toString(); 

	// ����������� �������������
	QString message = "Are you sure you want to delete the entry with id = " + id + "?";
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Deletion confirmation", message, QMessageBox::Yes | QMessageBox::No);

	// ���� ��� ��� ������������� �����, �� �������� ������� ������. � ������ ������� ������� � ������� ������
	// ���� ��� ��, ������������������ ������ ������
	if (reply == QMessageBox::Yes) 
	{
		QString queryStr = QString("DELETE FROM ") + DATABASE_NAME_CITIES + " WHERE id = " + id;
		QSqlQuery query(queryStr);
		if (!query.exec()) 
		{
			qDebug() << "Executing error: " << query.lastError();
		}
		else
		{
			ReInitModelQuery();
		}
	}
}
//-------------------------------------------------------------------

void MainTableCreator::OnEditButtonClicked()
{
	// ���������, ������ �� ������� ��� ��������������
	int row = TableView->currentIndex().row();
	if (row == -1)
		return;

	// �������������� ���� �������������� 
	QSqlRecord record = TableModel->record(row);

	EntryDataWindow* edit_window = new EntryDataWindow(this);
	edit_window->SetMode(EntryDataWindow::WorkingStatus::Edit);
	edit_window->SetData(record);

	edit_window->exec();

	// ����� ���������� ������������������ ������ � ������
	ReInitModelQuery();
}
//-------------------------------------------------------------------

void MainTableCreator::OnAddButtonClicked()
{
	// �������������� ���� ����������
	EntryDataWindow* edit_window = new EntryDataWindow(this);
	edit_window->SetMode(EntryDataWindow::WorkingStatus::Addition);
	edit_window->SetData();

	edit_window->exec();

	// ����� ���������� ������������������ ������ � ������
	ReInitModelQuery();
}
//-------------------------------------------------------------------

NumberDelegate::NumberDelegate()
{
}
//-------------------------------------------------------------------

NumberDelegate::~NumberDelegate()
{
}
//-------------------------------------------------------------------
