#include "Feature.h"

Feature::Feature(QString name, Type type, QImage img) {
	this->name = name;
	this->type = type;
	this->img = img;
	this->pos = QPoint(0, 0);
	this->rotate = 0;
}

void Feature::setRotate(int n) {
	this->rotate = n;
}

void Feature::setPos(QPoint pos) {
	this->pos = pos;
}

void Feature::setPos(int x, int y) {
	setPos(QPoint(x, y));
}