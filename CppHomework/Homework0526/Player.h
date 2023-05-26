#pragma once
#include "Global.h"
#include "Object.h"
#include <conio.h>
class ConsoleScreen;
class Player : public Object
{
public:
	const int4 Left = { -1, 0 };
	const int4 Right = { 1, 0 };
	const int4 Up = { 0, -1 };
	const int4 Down = { 0, 1 };

    void Input(ConsoleScreen*);
};

