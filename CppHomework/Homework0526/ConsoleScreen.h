#pragma once
#include "Global.h"
#include "Wall.h"
#include "Bullet.h"

class ConsoleScreen
{
public:

    bool Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;

    bool CollsionDetection(const int4& _Lpos, const int4& _Rpos);

    void Print() const;

    void SetWallPixel();

    void SetBulletPixel();

    int WallCollsionDetection(const int4& _Pos);

    void DestroyWall(int i);

    void AddBullet(const int4& _Pos, const int4& _Dir);

    void Update();

    int CountWall(); /* 테스트용 함수 */

    static const int XLine = 20;
    static const int YLine = 10;
protected:


private:
    static const int WallCount = 100;
    static const int MaxBullet = 50;
    int BulletCount = 0;
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
    Wall ArrWall[WallCount];
    Bullet ArrBullet[MaxBullet];
    int4 nullPos = { -1, -1 };
};

