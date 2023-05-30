#include "Bullet.h"
#include "ConsoleScreen.h"

Bullet::Bullet(const int4& _Pos, const int4& _Dir)
{
	Pos = _Pos;
	Dir = _Dir;
	ch = 'x';
	Active = true;
}

Bullet:: Bullet()
{
	ch = 'x';
}

void Bullet::Update(ConsoleScreen* const _Screen)
{

	if (_Screen == nullptr)
		return;

	if (false == _Screen->IsScreenOut(GetPos() + Dir) && -1 == _Screen->WallCollsionDetection(GetPos() + Dir))
	{
		AddPos(Dir);
	}
	else if (_Screen->WallCollsionDetection(GetPos() + Dir) != -1)
	{
		int i = _Screen->WallCollsionDetection(GetPos() + Dir);
		_Screen->DestroyWall(i);
		Active = false;
		Pos = { -1, -1 };
		Dir = { 0, 0 };
	}
	else 
	{
		Active = false;
		Pos = { -1, -1 };
		Dir = { 0, 0 };
	}
}