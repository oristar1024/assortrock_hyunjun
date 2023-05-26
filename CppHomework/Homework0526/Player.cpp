#include "Player.h"
#include "ConsoleScreen.h"

void Player::Input(ConsoleScreen* _Sreen)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = Left;
        break;
    case 'd':
        MovePos = Right;
        break;
    case 'w':
        MovePos = Up;
        break;
    case 's':
        MovePos = Down;
        break;
    default:
        break;
    }

    if (false == _Sreen->IsScreenOut(GetPos() + MovePos) && false == _Sreen->WallCollsionDetection(GetPos() + MovePos))
    {
        AddPos(MovePos);
    }

}