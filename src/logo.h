#ifndef LOGO_H
#define LOGO_H

#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class Logo:public QWidget
{
	Q_OBJECT

public:
	Logo(QWidget *parent=0);
	~Logo(void);

signals:
	void calculate(void);

private:
	QVBoxLayout *layout;
};

#endif /** LOGO_H **/
