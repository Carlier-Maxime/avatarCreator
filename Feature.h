#pragma once
#include <QPoint>
#include <QString>
#include <QImage>
#include "Type.h"

class Feature
{
private:
	QString name;
	Type type;
	QImage img;
	QPoint pos;
	int rotate;

public:
	Feature(QString name, Type type, QImage img);
	void setRotate(int n);
	void setPos(int x, int y);
	void setPos(QPoint pos);
};

