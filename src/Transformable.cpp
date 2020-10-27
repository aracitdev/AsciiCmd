#include <AsciiCmd/Transformable.h>

void Transformable::SetPosition(Vector2<int32_t> newPos)
{
    pos=newPos;
}

Vector2<int32_t> Transformable::GetPosition(void)
{
    return pos;
}

void Transformable::Move(Vector2<int32_t> d)
{
    pos=pos+d;
}
