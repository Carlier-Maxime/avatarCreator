#include "Utils.h"

const QString Utils::PATH_MAIN = "./";
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