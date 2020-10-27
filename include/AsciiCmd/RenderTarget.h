#ifndef RENDERTARGET_H_INCLUDED
#define RENDERTARGET_H_INCLUDED

namespace AsciiCmd
{
class Drawable;
class RenderTarget
{
public:

    virtual void PutPixel(Vector2<int32_t> pos, uint32_t character, int color)=0;
    virtual void Draw(Drawable& object)=0;
private:

};
}

#endif // RENDERTARGET_H_INCLUDED
