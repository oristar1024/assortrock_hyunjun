#pragma once
#include "Global.h"
#include "Object.h"
class ConsoleScreen;
class Player : public Object
{
	int4 Dir;
	
public:
	const int4 Left = { -1, 0 };
	const int4 Right = { 1, 0 };
	const int4 Up = { 0, -1 };
	const int4 Down = { 0, 1 };

	Player();

    void Input(ConsoleScreen* _Screen);
	void SetDir(const int4& _Pos);
	int4 GetDir() const;
	void Shoot(ConsoleScreen* _Screen);
};

