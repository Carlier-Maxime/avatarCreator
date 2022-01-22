#pragma once
#include <QtGui>

class Utils
{
public:
	static const QString PATH_MAIN;
	static const QString getSetting(QString name, bool toPath);
	static const QString getSetting(QString name);
};