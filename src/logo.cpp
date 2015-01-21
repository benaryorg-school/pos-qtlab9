#include <logo.h>

Logo::Logo(QWidget *parent):QWidget(parent)
{
	this->layout=new QVBoxLayout(this);
	this->setLayout(this->layout);

	QPushButton *calc=new QPushButton(tr("Calculate"),this);
	connect(calc,SIGNAL(pressed(void)),this,SIGNAL(calculate(void)));
	this->layout->addWidget(calc);

	QPushButton *quit=new QPushButton(tr("Quit"),this);
	connect(quit,SIGNAL(pressed(void)),QCoreApplication::instance(),SLOT(quit(void)));
	this->layout->addWidget(quit);

	QLabel *img=new QLabel(this);
	img->setPixmap(QPixmap(":/data/logo.png"));
	this->layout->addWidget(img);
}

Logo::~Logo(void)
{
}

