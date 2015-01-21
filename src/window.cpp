#include <window.h>

Window::Window(QWidget *parent):QWidget(parent)
{
	this->setWindowTitle(tr("Means"));

	QFrame *f;

	this->layout=new QHBoxLayout(this);
	this->setLayout(this->layout);
	this->splitter=new QSplitter(Qt::Vertical,this);
	this->layout->addWidget(this->splitter);

	QSplitter *top=new QSplitter(this);
	this->splitter->addWidget(top);
	QSplitter *bot=new QSplitter(this);
	this->splitter->addWidget(bot);

	this->input=new Input(this);
	f=new QFrame(this);
	f->setLayout(new QHBoxLayout(f));
	f->layout()->addWidget(this->input);
	f->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
	top->addWidget(f);

	this->options=new Options(this);
	f=new QFrame(this);
	f->setLayout(new QHBoxLayout(f));
	f->layout()->addWidget(this->options);
	f->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
	top->addWidget(f);

	this->logo=new Logo(this);
	connect(this->logo,SIGNAL(calculate(void)),this,SLOT(calculate(void)));
	f=new QFrame(this);
	f->setLayout(new QHBoxLayout(f));
	f->layout()->addWidget(this->logo);
	f->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
	bot->addWidget(f);

	this->results=new Results(this);
	connect(this->options,SIGNAL(checkBoxToggled(Averages,bool)),this->results,SLOT(toggle(Averages,bool)));
	connect(this->options,SIGNAL(sliderMoved(int)),this->results,SLOT(setKomma(int)));
	f=new QFrame(this);
	f->setLayout(new QHBoxLayout(f));
	f->layout()->addWidget(this->results);
	f->setFrameStyle(QFrame::StyledPanel|QFrame::Raised);
	bot->addWidget(f);
}

Window::~Window(void)
{
}

void Window::calculate(void)
{
	this->results->calculate(this->input->values());
}

