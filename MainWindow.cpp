#include "MainWindow.h"
#include "MainWidget.h"

MainWindow::MainWindow()
{
	setFixedSize(420,600);
	setStyleSheet("background-color: rgb(23, 93, 182)");
	setCentralWidget(new MainWidget(this));
}