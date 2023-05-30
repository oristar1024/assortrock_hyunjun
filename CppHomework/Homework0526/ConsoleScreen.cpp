#include "ConsoleScreen.h"
#include <iostream>
#include <random>
#include <set>


bool ConsoleScreen::Init(char _BaseCh)
{
    static bool once = false;

    if (once)
        return false;

    if ( WallCount > XLine * YLine - 1) 
    {
        printf("벽의 갯수가 최대값을 넘었습니다.\n");
        return false;
    }

    BaseCh = _BaseCh;
    Clear();
    std::random_device rd;
    std::default_random_engine dre(rd());
    std::uniform_int_distribution<int> uidX(0, XLine-1);
    std::uniform_int_distribution<int> uidY(0, YLine-1);
    int4 PlayerStartPos = { XLine/2,  YLine/2 };

    std::set<std::pair<int, int>> s;
    s.insert(std::make_pair(PlayerStartPos.X, PlayerStartPos.Y));

    for (int i = 0; i < WallCount; ++i)
    {
        int4 tmp = { uidX(dre), uidY(dre) };
        while (IsScreenOut(tmp))
            tmp = { uidX(dre), uidY(dre) };
        auto result = s.insert(std::make_pair(tmp.X, tmp.Y));
        if (result.second)
        {
            ArrWall[i].SetPos(tmp);
            SetPixel(ArrWall[i].GetPos(), ArrWall[i].ch);
            ArrWall[i].SetActive(true);
        }
        else 
        {
            --i;
        }
        /*
        int4 tmp = { uidX(dre), uidY(dre) };
        while (true == CollsionDetection(tmp, PlayerStartPos) || IsScreenOut(tmp)) 
        {
            tmp = { uidX(dre), uidY(dre) };
        }
        for (int j = 0; j < i; ++j) 
        {
            if (CollsionDetection(tmp, ArrWall[j].GetPos()) || CollsionDetection(tmp, PlayerStartPos) || IsScreenOut(tmp))
            {
                tmp = { uidX(dre, uidY(dre)) };
                j = -1;
            }
        }
        ArrWall[i].SetPos(tmp);
        SetPixel(ArrWall[i].GetPos(), ArrWall[i].ch);
        */
    }

    once = true;
    return true;
}

void ConsoleScreen::SetWallPixel() 
{
    for (int i = 0; i < WallCount; ++i)
    {
        if (ArrWall[i].isAcitve()) 
        {
            SetPixel(ArrWall[i].GetPos(), ArrWall[i].ch);
        }
    }
}

void ConsoleScreen::SetBulletPixel() 
{
    for (int i = 0; i < MaxBullet; ++i)
    {
        if (ArrBullet[i].isAcitve())
        {
            int4 tmp = ArrBullet[i].GetPos();
            SetPixel(ArrBullet[i].GetPos(), ArrBullet[i].ch);
        }
    }
}
void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
    if (IsScreenOut(_Pos) == false)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

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

bool ConsoleScreen::CollsionDetection(const int4& lPos, const int4& rPos) const
{
    return lPos == rPos;
}

int ConsoleScreen::WallCollsionDetection(const int4& _Pos) const
{
    for (int i = 0; i < WallCount; ++i) 
    {
        if (ArrWall[i].isAcitve() == false)
        {
            continue;
        }
        if (CollsionDetection(_Pos, ArrWall[i].GetPos()))
        {
            return i;
        }
    }
    return -1;
}

void ConsoleScreen::AddBullet(const int4& _Pos, const int4& _Dir) 
{
    ArrBullet[BulletCount] = Bullet(_Pos, _Dir);
    ArrBullet[BulletCount].SetActive(true);
    ++BulletCount;
    BulletCount %= MaxBullet;
}

void ConsoleScreen::Update() 
{
    for (int i = 0; i < MaxBullet; ++i) 
    {
        if (ArrBullet[i].isAcitve())
        {
            ArrBullet[i].Update(this);
        }
    }
}

void ConsoleScreen::DestroyWall(int i)
{
    ArrWall[i].SetActive(false);
    ArrWall[i].SetPos({ -1, -1 });
}

// 테스트용 함수
int ConsoleScreen::CountWall()
{
    int Count = 0;
    for (int i = 0; i < YLine; ++i)
        for (int j = 0; j < XLine; ++j) {
            if (ArrScreen[i][j] == '0')
                ++Count;
        }
    return Count;
}