#pragma once
#include "Global.h"

class Object
{
public:
    int4 GetPos() const;

    void AddPos(const int4&);

    void SetPos(const int4&);
protected:
    int4 Pos;
};

