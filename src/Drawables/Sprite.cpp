#include <AsciiCmd/Drawables/Sprite.h>
#include <AsciiCmd/RenderTarget.h>


namespace AsciiCmd
{

Sprite::Sprite(Texture* in)
{
    SetTexture(in);
}

void Sprite::SetTexture(Texture* in)
{
    tex=in;
}

Vector2<uint32_t> Sprite::GetSize(void)
{
    if(tex)
        return tex->GetSize();
    return Vector2<uint32_t>(0,0);
}

void Sprite::Draw(RenderTarget* target)
{
    if(!tex)
        return;
    Vector2<uint32_t> size= tex->GetSize();
    Vector2<uint32_t> currentpixel;
    for(currentpixel.y=0; currentpixel.y < size.y; currentpixel.y++)
        for(currentpixel.x=0; currentpixel.x < size.x; currentpixel.x++)
        {
            Texture::Pixel pix = tex->GetPixel(currentpixel);
            target->PutPixel(pos + currentpixel, pix.character, pix.color);
        }
}

}
