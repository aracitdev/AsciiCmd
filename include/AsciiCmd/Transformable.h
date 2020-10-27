#ifndef TRANSFORMABLE_H_INCLUDED
#define TRANSFORMABLE_H_INCLUDED
#include <AsciiCmd/Vector2.h>
#include <cstdint>

class Transformable
{
public:

    void SetPosition(Vector2<int32_t> newPos);
    Vector2<int32_t> GetPosition(void);
    void Move(Vector2<int32_t> d);

protected:
    Vector2<int32_t> pos;
};

#endif // TRANSFORMABLE_H_INCLUDED
