#include <results.h>
#include <cmath>

Results::Results(QWidget *parent):QWidget(parent)
{
	this->after=0;
	this->layout=new QGridLayout(this);
	this->setLayout(this->layout);

	this->layout->addWidget(new QLabel(tr("Arithmetic Mean"),this),0,0);
	this->arith=new QLineEdit(this);
	this->arith->setAlignment(Qt::AlignRight);
	this->arith->setReadOnly(true);
	this->arith->setPlaceholderText(QString());
	this->layout->addWidget(this->arith,0,1);

	this->layout->addWidget(new QLabel(tr("Geometric Mean"),this),1,0);
	this->geomet=new QLineEdit(this);
	this->geomet->setAlignment(Qt::AlignRight);
	this->geomet->setReadOnly(true);
	this->geomet->setPlaceholderText(QString());
	this->layout->addWidget(this->geomet,1,1);

	this->layout->addWidget(new QLabel(tr("Harmonic Mean"),this),2,0);
	this->harmon=new QLineEdit(this);
	this->harmon->setAlignment(Qt::AlignRight);
	this->harmon->setReadOnly(true);
	this->harmon->setPlaceholderText(QString());
	this->layout->addWidget(this->harmon,2,1);
}

Results::~Results(void)
{
}

void Results::calculate(QList<double> list)
{
	if(!this->arith->placeholderText().isEmpty())
	{
		double sum=0;
		foreach(double d,list)
		{
			sum+=d;
		}
		this->map[Arithmetic]=sum/list.size();
	}
	if(!this->geomet->placeholderText().isEmpty())
	{
		double sum=1;
		foreach(double d,list)
		{
			sum*=d;
			if(sum<0)
			{
				break;
			}
		}
		this->map[Geometric]=sum<0?NAN:pow(sum,1.0/list.size());
	}
	if(!this->harmon->placeholderText().isEmpty())
	{
		double a=0,sum=0;
		bool error=false;
		foreach(double d,list)
		{
			if(d<0)
			{
				error=true;
				break;
			}
			a+=d;
			sum+=1.0/d;
		}
		a/=list.size();
		this->map[Harmonic]=error?NAN:a/sum;
	}

	this->update();
}

void Results::toggle(Averages avg,bool on)
{
	switch(avg)
	{
		case Arithmetic:
			this->arith->setPlaceholderText(on?tr("NaN"):QString());
			this->arith->setText("");
			break;
		case Geometric:
			this->geomet->setPlaceholderText(on?tr("NaN"):QString());
			this->geomet->setText("");
			break;
		case Harmonic:
			this->harmon->setPlaceholderText(on?tr("NaN"):QString());
			this->harmon->setText("");
			break;
	}
}

void Results::update(void)
{
	if(!this->arith->placeholderText().isEmpty())
	{
		this->arith->setText(QString().sprintf("%.*lf",this->after,this->map[Arithmetic]));
	}
	if(!this->geomet->placeholderText().isEmpty())
	{
		this->geomet->setText(QString().sprintf("%.*lf",this->after,this->map[Geometric]));
	}
	if(!this->harmon->placeholderText().isEmpty())
	{
		this->harmon->setText(QString().sprintf("%.*lf",this->after,this->map[Harmonic]));
	}
}

void Results::setKomma(int i)
{
	this->after=i;
	this->update();
}

