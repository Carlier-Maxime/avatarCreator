#pragma once
#include <QtWidgets>

class MainWindow;

class MainWidget : public QWidget
{
private:
	QLabel *title;
	MainWindow* parent;
	void quitEvent();
	void generateAvatar();
	void newAssets();

public:
	MainWidget(MainWindow *parent);
};

