#pragma once
#include <QtGui>

class Avatar
{
private:
	static const QString PATH_BG;
	static const QString PATH_SKIN;
	static const QString PATH_AVATARS;
	static const int PERCENTAGE_OneColorBg;

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

