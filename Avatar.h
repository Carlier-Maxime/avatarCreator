#pragma once
#include <QtGui>

class Avatar
{
private:
	QImage* img;
	QImage* bg;
	QImage* skin;
	void randomAvatar();
	void randomBg();
	void randomSkin();
	void create();

public:
	Avatar();
	void save();
};

