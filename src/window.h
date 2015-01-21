#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>
#include <input.h>
#include <options.h>
#include <logo.h>
#include <results.h>

class Window:public QWidget
{
	Q_OBJECT

public:
	Window(QWidget *parent=0);
	~Window(void);

public slots:
	void calculate(void);
private:
	QHBoxLayout *layout;
	QSplitter *splitter;
	Input *input;
	Options *options;
	Logo *logo;
	Results *results;
};

#endif /** WINDOW_H **/
