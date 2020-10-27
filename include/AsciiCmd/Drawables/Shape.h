#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <AsciiCmd/Drawables/Drawable.h>
#include <AsciiCmd/Transformable.h>
#include <cstdint>

namespace AsciiCmd
{

class Shape: public Drawable, public Transformable
{
public:

    void SetFill(uint32_t character, int color);
    void SetOutline(uint32_t character, int color);

protected:
    int fillColor, outlineColor;
    uint32_t fillChar, outlineChar;
};

}
#endif // SHAPE_H_INCLUDED
