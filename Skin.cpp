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

QList<int> Skin::managementFeature(QString name, Type type, bool save, QPoint point, int rotate)
{
	QFile file = QFile(Utils::PATH_SKIN+"/bin/"+this->name+".bin");
	file.open(QIODevice::ReadWrite);
	QDataStream flux(&file);
	QString nameRead;
	int intType;
	int x, y, r;
	bool found = false;
	while (!flux.atEnd()) {
		flux >> nameRead >> intType;
		if (nameRead == name && intType == static_cast<int>(type))
		{
			found = true;
			break;
		}
		flux >> x >> y >> r;
	}
	if (save)
	{
		if (!found) flux << name << static_cast<int>(type);
		flux << point.x() << point.y() << rotate;
		file.close();
		return QList<int>({ point.x(), point.y(), rotate });
	}
	else
	{
		if (found) flux >> x >> y >> r;
		else { x = 0; y = 0; r = 0; }
		file.close();
		return QList<int>({x,y,r});
	}
	file.close();
	return QList<int>();
}

void Skin::saveInfoFeature(QString name, Type type, QPoint p, int rotate)
{
	managementFeature(name, type, true, p, rotate);
}

QPoint Skin::getPosFeature(QString name, Type type)
{
	QList<int> list = managementFeature(name,type,false,QPoint(),0);
	return QPoint(list.at(0), list.at(1));
}

int Skin::getRotateFeature(QString name, Type type)
{
	QList<int> list = managementFeature(name, type, false, QPoint(), 0);
	return list.at(2);
}