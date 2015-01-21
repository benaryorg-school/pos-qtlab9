#ifndef OPTIONS_H
#define OPTIONS_H

#include <enums.h>
#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class Options:public QWidget
{
	Q_OBJECT

public:
	Options(QWidget *parent=0);
	~Options(void);

public slots:
	void checkBoxAction(QWidget *w);

signals:
	void checkBoxToggled(Averages,bool);
	void sliderMoved(int);

private:
	QVBoxLayout *layout;
	QCheckBox *arith;
	QCheckBox *geomet;
	QCheckBox *harmon;
	QSlider *slider;
};

#endif /** OPTIONS_H **/
