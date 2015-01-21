#ifndef INPUT_H
#define INPUT_H

#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class Input:public QWidget
{
	Q_OBJECT

public:
	Input(QWidget *parent=0);
	~Input(void);

	QList<double> values(void);

public slots:
	void enterPressed(void);
	void addValue(const QString &str);
	void removeValue(void);

private:
	QGridLayout *layout;
	QLineEdit *edit;
	QListWidget *list;
	QMap<QListWidgetItem *,double> map;
};

#endif /** INPUT_H **/
