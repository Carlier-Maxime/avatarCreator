#include "Skin.h"
#include "Utils.h"

const QList<QColor> Skin::listHumanColors =
{
	QColor(227,195,182),
	QColor(227,163,125),
	QColor(92,39,31),
	QColor(19,1,1)
};
const QList<QColor> Skin::listAlienColors =
{
	QColor(157,62,249),
	QColor(18,32,128),
	QColor(0,117,105),
	QColor(0,183,7),
	QColor(141,52,52)
};
const int Skin::PAS_COLOR = 100;

Skin::Skin(QString name)
{
	this->name = name;
	QImage img = QImage(Utils::PATH_SKIN+'/'+name+".png");
	original = img;
	this->img = original.copy();
	alien = ((rand() % 101) <= Utils::PERCENTAGE_ALIEN) ? true : false;
	baseColor = randomColor();
	paint();
}

QColor Skin::randomColor()
{
	if (alien) return randomAlienColor();
	else return randomHumanColor();
}

QColor Skin::randomColor(const QList<QColor>* listColors)
{
	int i = rand() % ((listColors->size()-1)*PAS_COLOR);
	int j = i / PAS_COLOR;
	int pas = i % PAS_COLOR;
	int r = listColors->at(j).red();
	int g = listColors->at(j).green();
	int b = listColors->at(j).blue();
	if (pas == 0) return QColor(r, g, b);
	float incR = ((listColors->at(j + 1).red() - r) * 1.0)/ PAS_COLOR;
	float incG = ((listColors->at(j + 1).green() - g) * 1.0)/ PAS_COLOR;
	float incB = ((listColors->at(j + 1).blue() - b) * 1.0)/ PAS_COLOR;
	return QColor(r + incR * pas, g + incG * pas, b + incB * pas);
}

QColor Skin::randomHumanColor()
{
	return randomColor(&listHumanColors);
}

QColor Skin::randomAlienColor()
{
	return randomColor(&listAlienColors);
}

void Skin::paint()
{
	img = original.copy();
	for (int i = 0; i < img.height(); i++)
	{
		for (int j = 0; j < img.width(); j++)
		{
			QColor color = img.pixelColor(j, i);
			if (color.alpha()!=0)
			{
				int light = (color.red() + color.green() + color.blue()) / 3;
				img.setPixelColor(j, i, Utils::darkenColor(baseColor, light));
			}
		}
	}
}

QImage Skin::getImg()
{
	return img;
}

bool Skin::isAlien()
{
	return alien;
}

QString Skin::getInfoFeature(QString name, Type type)
{
	QFile file = QFile(Utils::PATH_SKIN+"/bin/"+name+".bin");
	return "";
}