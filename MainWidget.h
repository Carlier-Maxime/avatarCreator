#pragma once
#include <QtWidgets>

class MainWindow;

class MainWidget : public QWidget
{
private:
	QLabel *title;
	MainWindow* parent;
	void quitEvent();
	QWidget* genHbox();

public:
	MainWidget(MainWindow *parent);
};

