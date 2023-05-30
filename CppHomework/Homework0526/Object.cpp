#include "Object.h"

int4 Object::GetPos() const
{
    return Pos;
}

void Object::AddPos(const int4& _Pos)
{
    Pos += _Pos;
}


void Object::SetPos(const int4& _Pos)
{
    Pos = _Pos;
}

void Object::SetActive(const bool _Active)
{
    Active = _Active;
}

bool Object::isAcitve() const
{
    return Active;
}