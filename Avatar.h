#pragma once
#include <QtGui>
#include "Skin.h"

class Avatar
{
private:
	static const QString PATH_BG;
	static const QString PATH_SKIN;
	static const QString PATH_AVATARS;
	static const int PERCENTAGE_OneColorBg;

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

