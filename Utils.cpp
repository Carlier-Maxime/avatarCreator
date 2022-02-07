#include "Utils.h"

const QString Utils::PATH_MAIN = "./";
const QString Utils::PATH_BG = Utils::getSetting("PATH_BG", true);
const QString Utils::PATH_SKIN = Utils::getSetting("PATH_SKIN", true);
const QString Utils::PATH_AVATARS = Utils::getSetting("PATH_AVATARS", true);

const int Utils::PERCENTAGE_OneColorBg = Utils::getSetting("PERCENTAGE_OneColorBg").toInt();
const int Utils::PERCENTAGE_ALIEN = Utils::getSetting("PERCENTAGE_ALIEN").toInt();

const QString Utils::getSetting(QString name, bool toPath)
{
	QFile file(PATH_MAIN + "settings.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return PATH_MAIN;
	QTextStream flux(&file);
	while (!flux.atEnd())
	{
		QStringList line = flux.readLine().split(" ");
		if (line.at(0) == name)
		{
			QString s = line.at(2);
			file.close();
			if (toPath) return PATH_MAIN + s;
			else return s;
		}
	}
	file.close();
	return PATH_MAIN;
}

const QString Utils::getSetting(QString name)
{
	return getSetting(name, false);
}

QColor Utils::darkenColor(QColor color, int light)
{
	int r = (light * color.red()) / 255;
	int g = (light * color.green()) / 255;
	int b = (light * color.blue()) / 255;
	return QColor(r,g,b);
}

QWidget* Utils::genHbox(QWidget* parent)
{
	QWidget* hbox = new QWidget();
	hbox->setFixedWidth(parent->width());
	hbox->setLayout(new QHBoxLayout());
	hbox->layout()->setContentsMargins(0, 0, 0, 0);
	hbox->layout()->setAlignment(Qt::AlignCenter);
	return hbox;
}