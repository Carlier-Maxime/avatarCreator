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
	static const int PERCETAGE_ALIEN;

	QImage original;
	QImage img;
	QColor baseColor;
	bool alien;

	void randomColor();
	void randomHumanColor();
	void randomAlienColor();
	void paint();

public:
	Skin(QImage img);

	QImage getImg();
	bool isAlien();
};

