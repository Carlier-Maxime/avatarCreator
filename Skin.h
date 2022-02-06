#pragma once
#include <QList>
#include <QColor>
#include <QImage>
#include "Type.h"

class Skin
{
private:
	static const QList<QColor> listHumanColors;
	static const QList<QColor> listAlienColors;
	static const int PAS_COLOR;

	QString name;
	QImage original;
	QImage img;
	QColor baseColor;
	bool alien;

	QColor randomColor();
	QColor randomColor(const QList<QColor>* listColors);
	QColor randomHumanColor();
	QColor randomAlienColor();
	void paint();
	int getPosInfoFeature(QString name, Type type);

public:
	Skin(QString name);

	QImage getImg();
	bool isAlien();
	void saveInfoFeature(QString name, Type type, QPoint p, int rotate);
};

