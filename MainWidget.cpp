#include "MainWidget.h"

MainWidget::MainWidget()
{
	setLayout(new QVBoxLayout());
	// title
	title = new QLabel(this);
	title->setText("Avatar Creator");
	title->setStyleSheet("color: rgb(6,159,50)");
	layout()->addWidget(title);
	//generate
	QPushButton *buttonGenerate = new QPushButton("Generate",this);
	buttonGenerate->setStyleSheet("background-color: rgb(6,159,50)");
	layout()->addWidget(buttonGenerate);
	//quit
	QPushButton* buttonQuit = new QPushButton("Quit",this);
	buttonQuit->setStyleSheet("background-color: rgb(6,159,50)");
	connect(buttonQuit, &QPushButton::clicked, this, &MainWidget::quitEvent);
	layout()->addWidget(buttonQuit);
}

void MainWidget::quitEvent()
{
	exit(0);
}