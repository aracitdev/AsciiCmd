#include <AsciiCmd/Drawables/Rectangle.h>
#include <AsciiCmd/RenderTarget.h>

namespace AsciiCmd
{
    Rectangle::Rectangle(Vector2<uint32_t> size)
    {
        shapeSize=size;
    }


    void Rectangle::Draw(RenderTarget* target)
    {
        Vector2<int32_t> counter;
        for(counter.x=0; (uint32_t)counter.x < shapeSize.x; counter.x++)
            for(counter.y=0; (uint32_t)counter.y < shapeSize.y; counter.y++)
            {
                if(counter.x == 0 || counter.y == 0 || (uint32_t)counter.x == shapeSize.x-1 || (uint32_t)counter.y == shapeSize.y-1)
                    target->PutPixel(counter + pos, outlineChar,outlineColor);
                else
                    target->PutPixel(counter + pos, fillChar, fillColor);
            }

    }

    Vector2<uint32_t> Rectangle::GetSize(void)
    {
        return shapeSize;
    }

    void Rectangle::SetSize(Vector2<uint32_t> sz)
    {
        shapeSize=sz;
    }
}
