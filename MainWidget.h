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
	void generateAvatar();

public:
	MainWidget(MainWindow *parent);
};

