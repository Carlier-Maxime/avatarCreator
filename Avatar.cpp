#include "Avatar.h"
#include <random>

const QString Avatar::PATH_BG = Avatar::getSetting("PATH_BG");
const QString Avatar::PATH_SKIN = Avatar::getSetting("PATH_SKIN");
const QString Avatar::PATH_AVATARS = Avatar::getSetting("PATH_AVATARS");
const int Avatar::PERCENTAGE_OneColorBg = Avatar::getSetting("PERCENTAGE_OneColorBg").toInt();

const QString Avatar::getSetting(QString name)
{
	QFile file("settings.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return "../.";
	QTextStream flux(&file);
	while (!flux.atEnd())
	{
		QStringList line = flux.readLine().split(" ");
		if (line.at(0) == name)
		{
			QString s = line.at(2);
			file.close();
			return s;
		}
	}
	file.close();
	return ".";
}

Avatar::Avatar()
{
	randomAvatar();
}

void Avatar::save()
{
	if (img==nullptr) return;
	img->save(PATH_AVATARS+"/avatar.jpg");
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
	QDir dir = QDir(PATH_BG);
	int n = rand() % 101;
	if (n <= PERCENTAGE_OneColorBg)
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
	QDir dir = QDir(PATH_SKIN);
	int i = rand() % (dir.count()-2) + 2;
	skin = new QImage(dir.path()+'/'+dir.entryList().at(i));
}