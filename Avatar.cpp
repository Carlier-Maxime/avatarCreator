#include "Avatar.h"

Avatar::Avatar()
{
	img = new QImage("assets/skin0.png");
}

void Avatar::save()
{
	if (img==nullptr) return;
	img->save("avatars/avatar.jpg");
}