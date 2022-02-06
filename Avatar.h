#pragma once
#include <QtGui>
#include "Skin.h"

class Avatar
{
private:
	QString name;
	QImage* img;
	QImage* bg;
	Skin* skin;

	void randomAvatar();
	void randomBg();
	void randomSkin();
	void create();

public:
	Avatar(QString name);
	Avatar();
	~Avatar();

	void save();
};

