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

int Skin::getPosInfoFeature(QString name, Type type)
{
	QFile file = QFile(Utils::PATH_SKIN+"/bin/"+this->name+".bin");
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	QString nameRead;
	int intType;
	int a, b, c;
	while (!in.atEnd()) {
		in >> nameRead >> intType;
		if (nameRead == name && intType == static_cast<int>(type)) return file.pos();
		else
		{
			in >> a >> b >> c;
		}
	}
	file.close();
	return -1;
}

void Skin::saveInfoFeature(QString name, Type type, QPoint p, int rotate)
{
	int pos = getPosInfoFeature(name, type);
	QFile file = QFile(Utils::PATH_SKIN + "/bin/" + this->name + ".bin");
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	if (pos >= 0) file.seek(pos);
	else out << name << static_cast<int>(type);
	out << p.x() << p.y() << rotate;
}

QPoint Skin::getPosFeature(QString name, Type type)
{
	int pos = getPosInfoFeature(name, type);
	if (pos < 0) return QPoint();
	QFile file = QFile(Utils::PATH_SKIN + "/bin/" + this->name + ".bin");
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	int x, y;
	in >> x >> y;
	return QPoint(x, y);
}

int Skin::getRotateFeature(QString name, Type type)
{
	int pos = getPosInfoFeature(name, type);
	if (pos < 0) return 0;
	QFile file = QFile(Utils::PATH_SKIN + "/bin/" + this->name + ".bin");
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	int r;
	in >> r >> r >> r;
	return r;
}