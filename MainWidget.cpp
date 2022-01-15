#include "MainWidget.h"
#include "MainWindow.h"
#include "Avatar.h"

MainWidget::MainWidget(MainWindow *parent)
{
	setLayout(new QVBoxLayout());
	this->parent = parent;
	int w = parent->width();
	int h = parent->height();
	// title
	title = new QLabel(this);
	title->setText("Avatar Creator ");
	title->setStyleSheet("color: rgb(6,159,50)");
	title->setFont(QFont("Comic Sans MS",40,QFont::Bold));
	title->setAlignment(Qt::AlignCenter);
	title->setFixedSize(w, h*0.10);
	layout()->addWidget(title);
	//generate
	QWidget* hbox = genHbox();
	QPushButton *buttonGenerate = new QPushButton("Generate",this);
	buttonGenerate->setStyleSheet("background-color: rgb(6,159,50)");
	buttonGenerate->setFixedSize(w*0.25,h*0.10);
	connect(buttonGenerate, &QPushButton::clicked, this, &MainWidget::generateAvatar);
	hbox->layout()->addWidget(buttonGenerate);
	layout()->addWidget(hbox);
	//quit
	hbox = genHbox();
	QPushButton* buttonQuit = new QPushButton("Quit",this);
	buttonQuit->setStyleSheet("background-color: rgb(6,159,50)");
	buttonQuit->setFixedSize(w * 0.25, h * 0.10);
	connect(buttonQuit, &QPushButton::clicked, this, &MainWidget::quitEvent);
	hbox->layout()->addWidget(buttonQuit);
	layout()->addWidget(hbox);
}

void MainWidget::quitEvent()
{
	exit(0);
}

QWidget* MainWidget::genHbox()
{
	QWidget *hbox = new QWidget();
	hbox->setFixedWidth(parent->width());
	hbox->setLayout(new QHBoxLayout());
	hbox->layout()->setContentsMargins(0, 0, 0, 0);
	hbox->layout()->setAlignment(Qt::AlignCenter);
	return hbox;
}

void MainWidget::generateAvatar()
{
	Avatar avatar = Avatar();
	avatar.save();
}