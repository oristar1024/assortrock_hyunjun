#pragma once
#include "Object.h"
#include "Global.h"
class ConsoleScreen;
class Bullet : public Object
{
	int4 Dir;
public:
	Bullet();
	Bullet(const int4& _Pos, const int4& _Dir);
	void Update(ConsoleScreen* const _Screen);
};

