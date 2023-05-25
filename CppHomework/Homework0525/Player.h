#pragma once

class Player
{
public:
	void StatusRender();

	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att);

	// 
	const char* GetName();

	int GetAtt();

	bool IsDeath();



private:
	// Ä¸½¶È­
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
	static const int LineCount = 40;
};