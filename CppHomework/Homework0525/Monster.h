#pragma once

class Monster
{
public:
	void StatusRender();

	void DamagePrint(const char* const, int);

	void Damage(int);

	const char* GetName();

	int GetAtt();

	bool IsDeath();

private:
	// ĸ��ȭ
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};