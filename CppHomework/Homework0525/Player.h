#pragma once

class Player
{
public:
	void StatusRender();

	void DamagePrint(const char* const, int);

	void Damage(int);

	const char* GetName();

	int GetAtt();

	bool IsDeath();



private:
	// Ä¸½¶È­
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
};