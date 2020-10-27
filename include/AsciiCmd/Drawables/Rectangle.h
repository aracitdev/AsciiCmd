#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <AsciiCmd/Drawables/Shape.h>

namespace AsciiCmd
{

class Rectangle: public Shape
{
public:
    Rectangle(Vector2<uint32_t> size=Vector2<uint32_t>(0,0));

    void SetSize(Vector2<uint32_t> sz);
    Vector2<uint32_t> GetSize(void);

    virtual void Draw(RenderTarget*);
private:
    Vector2<uint32_t> shapeSize;
};

}
#endif // RECTANGLE_H_INCLUDED
