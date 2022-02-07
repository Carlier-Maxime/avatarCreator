#include "MainWindow.h"
#include "MainWidget.h"
#include "Utils.h"

MainWindow::MainWindow()
{
	setFixedSize(420,600);
	setStyleSheet("background-color: "+Utils::strSecondColor());
	setCentralWidget(new MainWidget(this));
}