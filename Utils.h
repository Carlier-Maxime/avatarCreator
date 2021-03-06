#pragma once
#include <QtGui>
#include <QtWidgets>

class Utils
{
public:
	static const QString PATH_MAIN;
	static const QString PATH_BG;
	static const QString PATH_SKIN;
	static const QString PATH_AVATARS;

	static const int PERCENTAGE_OneColorBg;
	static const int PERCENTAGE_ALIEN;

	static const QColor firstColor;
	static const QColor secondColor;

	static const QString getSetting(QString name, bool toPath);
	static const QString getSetting(QString name);
	static QColor darkenColor(QColor color, int light);
	static QWidget* HBox(QWidget* parent);
	static const QString strFirstColor();
	static const QString strSecondColor();
};