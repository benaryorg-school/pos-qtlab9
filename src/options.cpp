#include <options.h>

Options::Options(QWidget *parent):QWidget(parent)
{
	this->layout=new QVBoxLayout(this);
	this->setLayout(this->layout);

	QSignalMapper *mapper=new QSignalMapper(this);
	connect(mapper,SIGNAL(mapped(QWidget *)),this,SLOT(checkBoxAction(QWidget *)));

	this->arith=new QCheckBox(tr("Arithmetic Mean"),this);
	connect(this->arith,SIGNAL(stateChanged(int)),mapper,SLOT(map()));
	mapper->setMapping(this->arith,this->arith);
	this->layout->addWidget(this->arith);

	this->geomet=new QCheckBox(tr("Geometric Mean"),this);
	connect(this->geomet,SIGNAL(stateChanged(int)),mapper,SLOT(map()));
	mapper->setMapping(this->geomet,this->geomet);
	this->layout->addWidget(this->geomet);

	this->harmon=new QCheckBox(tr("Harmonic Mean"),this);
	connect(this->harmon,SIGNAL(stateChanged(int)),mapper,SLOT(map()));
	mapper->setMapping(this->harmon,this->harmon);
	this->layout->addWidget(this->harmon);

	QSlider *slider=new QSlider(Qt::Horizontal,this);
	slider->setTickInterval(1);
	slider->setTickPosition(QSlider::TicksBelow);
	slider->setMinimum(0);
	slider->setMaximum(6);
	slider->setTracking(false);
	connect(slider,SIGNAL(sliderMoved(int)),this,SIGNAL(sliderMoved(int)));
	this->layout->addWidget(slider);
}

Options::~Options(void)
{
}

void Options::checkBoxAction(QWidget *w)
{
	QCheckBox *box=reinterpret_cast<QCheckBox *>(w);
	Averages avg;
	switch(box->text()[0].cell())
	{
		case 'A':
			avg=Arithmetic;
			break;
		case 'G':
			avg=Geometric;
			break;
		case 'H':
			avg=Harmonic;
			break;
		default:
			return;
			break;
	}
	emit checkBoxToggled(avg,box->isChecked());
}

