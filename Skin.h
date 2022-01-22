#pragma once
#include <QList>
#include <QColor>
#include <QImage>

class Skin
{
private:
	static const QList<QColor> listHumanColors;
	static const QList<QColor> listAlienColors;
	static const int PAS_COLOR;
	static const int PERCENTAGE_ALIEN;

	QImage original;
	QImage img;
	QColor baseColor;
	bool alien;

	QColor randomColor();
	QColor randomColor(const QList<QColor>* listColors);
	QColor randomHumanColor();
	QColor randomAlienColor();
	void paint();

public:
	Skin(QImage img);

	QImage getImg();
	bool isAlien();
};

