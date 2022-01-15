#pragma once
#include <QtWidgets>

class MainWidget : public QWidget
{
private:
	QLabel *title;
	void quitEvent();

public:
	MainWidget();
};

