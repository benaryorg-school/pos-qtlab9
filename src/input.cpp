#include <input.h>

Input::Input(QWidget *parent):QWidget(parent)
{
	this->layout=new QGridLayout(this);
	this->edit=new QLineEdit(this);
	QPushButton *add=new QPushButton(tr("Add"),this);
	QPushButton *del=new QPushButton(tr("Delete"),this);
	QPushButton *cls=new QPushButton(tr("Clear"),this);
	this->list=new QListWidget(this);

	this->edit->setValidator(new QDoubleValidator(this));
	this->edit->setPlaceholderText(tr("Value"));
	connect(edit,SIGNAL(returnPressed(void)),this,SLOT(enterPressed(void)));
	connect(add,SIGNAL(clicked(void)),this,SLOT(enterPressed(void)));

	connect(del,SIGNAL(clicked(void)),this,SLOT(removeValue(void)));

	connect(cls,SIGNAL(clicked(void)),this->list,SLOT(clear(void)));

	this->list->setSelectionMode(QAbstractItemView::MultiSelection);

	this->layout->addWidget(this->edit,0,0);
	this->layout->addWidget(add,1,0);
	this->layout->addWidget(del,2,0);
	this->layout->addWidget(cls,3,0);
	this->layout->addWidget(this->list,0,1,4,1);
}

Input::~Input(void)
{
}

void Input::enterPressed(void)
{
	QString str=this->edit->text();
	if(!str.isEmpty())
	{
		emit this->addValue(str);
	}
}

void Input::addValue(const QString &str)
{
	QListWidgetItem *i=new QListWidgetItem(QString().sprintf("%.2lf",str.toDouble()),this->list);
	i->setTextAlignment(Qt::AlignRight);
	this->edit->setText(QString());
	this->map[i]=str.toDouble();
}

void Input::removeValue(void)
{
	QList<QListWidgetItem *> list=this->list->selectedItems();
	foreach(QListWidgetItem *i,list)
	{
		this->map.remove(i);
		delete i;
	}
}

QList<double> Input::values(void)
{
	return this->map.values();
}

