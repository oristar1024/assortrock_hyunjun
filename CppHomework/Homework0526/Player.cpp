#include "Player.h"
#include "ConsoleScreen.h"
#include <conio.h>

void Player::Input(ConsoleScreen* _Screen)
{
    if (_Screen == nullptr)
        return;

    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = Left;
        SetDir(Left);
        break;
    case 'd':
        MovePos = Right;
        SetDir(Right);
        break;
    case 'w':
        MovePos = Up;
        SetDir(Up);
        break;
    case 's':
        MovePos = Down;
        SetDir(Down);
        break;
    case ' ':
        Shoot(_Screen);
        break;
    default:
        break;
    }

    if (false == _Screen->IsScreenOut(GetPos() + MovePos) && -1 == _Screen->WallCollsionDetection(GetPos() + MovePos))
    {
        AddPos(MovePos);
    }

}

void Player::SetDir(const int4& _Dir) 
{
    Dir = _Dir;

    if (_Dir == Up)
        ch = '^';
    else if (_Dir == Down)
        ch = 'v';
    else if (_Dir == Left)
        ch = '<';
    else if (_Dir == Right)
        ch = '>';
        
}

int4 Player::GetDir() const
{
    return Dir;
}

void Player::Shoot(ConsoleScreen* _Screen)
{
    if (_Screen == nullptr)
        return;
    _Screen->AddBullet(Pos, Dir);
}

Player::Player()
{
    Dir = Down;
    ch = 'v';
}