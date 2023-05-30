#pragma once
#include "Global.h"
#include "Wall.h"
#include "Bullet.h"

class ConsoleScreen
{
public:

    bool Init(const char _BaseCh);

    void SetPixel(const int4& _Pos, const char _Ch);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;

    bool CollsionDetection(const int4& _Lpos, const int4& _Rpos) const;

    void Print() const;

    void SetWallPixel();

    void SetBulletPixel();

    int WallCollsionDetection(const int4& _Pos) const;

    void DestroyWall(int i);

    void AddBullet(const int4& _Pos, const int4& _Dir);

    void Update();

    int CountWall(); /* 테스트용 함수 */

    static const int XLine = 20;
    static const int YLine = 10;
protected:


private:
    static const int WallCount = 150;
    static const int MaxBullet = 50;
    int BulletCount = 0;
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
    Wall ArrWall[WallCount];
    Bullet ArrBullet[MaxBullet];
};

