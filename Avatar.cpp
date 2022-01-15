#include "Avatar.h"

Avatar::Avatar()
{
	img = nullptr;
}

void Avatar::save()
{
	if (img==nullptr) return;
	img->save("avatar.jpg");
}