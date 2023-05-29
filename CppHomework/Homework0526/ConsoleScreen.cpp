#include "ConsoleScreen.h"
#include <iostream>
#include <random>
#include <Windows.h>


void ConsoleScreen::Init(char _BaseCh)
{
    BaseCh = _BaseCh;
    Clear();
    std::random_device rd;
    std::default_random_engine dre(rd());
    std::uniform_int_distribution<int> uidX(0, XLine-1);
    std::uniform_int_distribution<int> uidY(0, YLine-1);

    for (int i = 0; i < WallCount; ++i)
    {
        ArrWall[i] = Wall();
        int4 tmp = { uidX(dre), uidY(dre) };
        for (int j = 0; j < i; ++j) 
        {
            if (CollsionDetection(tmp, ArrWall[j].GetPos())) 
            {
                tmp = { uidX(dre, uidY(dre)) };
                j = -1;
            }
        }
        ArrWall[i].SetPos(tmp);
        SetPixel(ArrWall[i].GetPos(), ArrWall[i].ch);
    }
}

void ConsoleScreen::SetWallPixel() 
{
    for (int i = 0; i < WallCount; ++i)
    {
        if (ArrWall[i].GetPos() != nullPos) 
        {
            SetPixel(ArrWall[i].GetPos(), ArrWall[i].ch);
        }
    }
}

void ConsoleScreen::SetBulletPixel() 
{
    for (int i = 0; i < MaxBullet; ++i)
    {
        if (ArrBullet[i].GetPos() != nullPos)
        {
            int4 tmp = ArrBullet[i].GetPos();
            SetPixel(ArrBullet[i].GetPos(), ArrBullet[i].ch);
        }
    }
}
void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
    ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleScreen::Clear()
{
    system("cls");
    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
    }
    SetWallPixel();
    SetBulletPixel();
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (XLine <= _Pos.X)
    {
        return true;
    }

    if (YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}


void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}

bool ConsoleScreen::CollsionDetection(const int4& lPos, const int4& rPos)
{
    return lPos == rPos;
}

int ConsoleScreen::WallCollsionDetection(const int4& _Pos)
{
    for (int i = 0; i < WallCount; ++i) 
    {
        if (CollsionDetection(_Pos, ArrWall[i].GetPos()))
            return i;
    }
    return -1;
}

void ConsoleScreen::AddBullet(const int4& _Pos, const int4& _Dir) 
{
    ArrBullet[BulletCount] = Bullet(_Pos, _Dir);
    ++BulletCount;
    BulletCount %= MaxBullet;
}

void ConsoleScreen::Update() 
{
    for (int i = 0; i < MaxBullet; ++i) 
    {
        if (ArrBullet[i].GetPos() != nullPos)
        {
            ArrBullet[i].Update(this);
        }
    }
}

void ConsoleScreen::DestroyWall(int i)
{
    ArrWall[i].SetPos(nullPos);
}