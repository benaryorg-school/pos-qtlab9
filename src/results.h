#ifndef RESULTS_H
#define RESULTS_H

#include <enums.h>
#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class Results:public QWidget
{
	Q_OBJECT

public:
	Results(QWidget *parent=0);
	~Results(void);

public slots:
	void calculate(QList<double> list);
	void toggle(Averages avg,bool on);
	void update(void);
	void setKomma(int i);

private:
	QGridLayout *layout;
	QLineEdit *arith;
	QLineEdit *geomet;
	QLineEdit *harmon;
	QMap<Averages,double> map;
	int after;
};

#endif /** RESULTS_H **/
