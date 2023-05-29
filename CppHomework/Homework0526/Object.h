#pragma once
#include "Global.h"

class Object
{
public:
    int4 GetPos() const;

    void AddPos(const int4& _Pos);

    void SetPos(const int4& _Pos);

    char ch;
protected:
    int4 Pos;
};

