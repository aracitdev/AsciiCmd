#include <AsciiCmd/Drawables/Shape.h>

namespace AsciiCmd
{

void Shape::SetFill(uint32_t character, int color)
{
    fillColor=color;
    fillChar=character;
}

void Shape::SetOutline(uint32_t character, int color)
{
    outlineColor=color;
    outlineChar=character;
}

}
