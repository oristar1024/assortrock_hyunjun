#pragma once
#include "Global.h"
#include "Wall.h"

class ConsoleScreen
{
public:

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    bool IsScreenOut(const int4&) const;

    bool CollsionDetection(const int4&, const int4&);

    void Print() const;

    void SetWallPixel();

    bool WallCollsionDetection(const int4&);
protected:


private:
    static const int WallCount = 10;
    static const int XLine = 20;
    static const int YLine = 10;
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
    Wall ArrWall[WallCount];
};

