#include <iostream>
#include "Player.h"

	void Player::StatusRender()
	{
		int Count = 0;

		Count = StringCount(Name);

		// 40개로 맞춰오세요.

		// 줄바꿈이 안되고 있습니다.
		printf_s("%s", Name);

		for (size_t i = 0; i < LineCount - Count; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

		printf_s("공격력 : %d\n", Att);
		printf_s("체  력 : %d\n", Hp);
		for (size_t i = 0; i < LineCount; i++)
		{
			printf_s("-");
		}
		printf_s("\n");

	}

	void Player::DamagePrint(const char* const _AttName, int _Att)
	{
		printf_s("%s가 %s를 공격했습니다.\n", _AttName, Name);
		printf_s("%s는 %d의 데미지를 입었습니다.\n", Name, _Att);
	}

	void Player::Damage(int _Att)
	{
		Hp -= _Att;
	}

	// 
	const char* Player::GetName()
	{
		return Name;
	}

	int Player::GetAtt()
	{
		return Att;
	}

	bool Player::IsDeath()
	{
		return Hp <= 0;
	}