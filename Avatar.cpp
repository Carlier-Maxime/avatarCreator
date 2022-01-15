#include "Avatar.h"
#include <random>

Avatar::Avatar()
{
	randomAvatar();
}

void Avatar::save()
{
	if (img==nullptr) return;
	img->save("avatars/avatar.jpg");
}

void Avatar::create()
{
	img = new QImage(64, 64, QImage::Format::Format_RGB32);
	if (bg == nullptr || skin == nullptr) return;
	for (int i = 0; i < 64; i++)
	{
		for (int j=0; j<64; j++)
		{
			if (skin->pixelColor(i,j).alpha()==0) img->setPixelColor(i, j, bg->pixelColor(i, j));
			else img->setPixelColor(i, j, skin->pixelColor(i, j));
		}
	}
}

void Avatar::randomAvatar()
{
	randomBg();
	randomSkin();
	create();
}

void Avatar::randomBg()
{
	QDir dir = QDir("assets/bg");
	int i = rand() % (dir.count()-2) + 2;
	bg = new QImage(dir.path()+'/'+dir.entryList().at(i));
}

void Avatar::randomSkin()
{
	QDir dir = QDir("assets/skin");
	int i = rand() % (dir.count()-2) + 2;
	skin = new QImage(dir.path()+'/'+dir.entryList().at(i));
}