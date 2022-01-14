#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QMainWindow mainWindow;
	mainWindow.setWindowState(Qt::WindowMaximized);
	mainWindow.show();

	return app.exec();
}