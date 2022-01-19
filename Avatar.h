#pragma once
#include <QtGui>

class Avatar
{
private:
	static const QString getSetting(QString name);
	static const QString PATH_BG;
	static const QString PATH_SKIN;
	static const QString PATH_AVATARS;
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

