#include "Avatar.h"
#include <random>
#include "Utils.h"

Avatar::Avatar(QString name)
{
	this->name = name;
	randomAvatar();
}

Avatar::Avatar()
{
	name = "avatar";
	Avatar(name);
}

void Avatar::save()
{
	if (img==nullptr) return;
	img->save(Utils::PATH_AVATARS+"/"+name+".jpg");
}

void Avatar::create()
{
	img = new QImage(64, 64, QImage::Format::Format_RGB32);
	if (bg == nullptr || skin == nullptr) return;
	for (int i = 0; i < 64; i++)
	{
		for (int j=0; j<64; j++)
		{
			if (skin->getImg().pixelColor(i,j).alpha()==0) img->setPixelColor(i, j, bg->pixelColor(i, j));
			else img->setPixelColor(i, j, skin->getImg().pixelColor(i, j));
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
	QDir dir = QDir(Utils::PATH_BG);
	int n = rand() % 101;
	if (n <= Utils::PERCENTAGE_OneColorBg)
	{
		bg = new QImage(64, 64, QImage::Format_RGB32);
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		bg->fill(QColor(r,g,b));
	}
	else
	{
		int i = rand() % (dir.count() - 2) + 2;
		bg = new QImage(dir.path() + '/' + dir.entryList().at(i));
	}
}

void Avatar::randomSkin()
{
	QDir dir = QDir(Utils::PATH_SKIN);
	int i = rand() % (dir.count()-2) + 2;
	skin = new Skin(dir.entryList().at(i).split(".").at(0));
}

Avatar::~Avatar()
{
	delete img;
	delete bg;
	delete skin;
}