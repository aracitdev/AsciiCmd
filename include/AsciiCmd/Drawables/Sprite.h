#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include <AsciiCmd/Drawables/Drawable.h>
#include <AsciiCmd/Transformable.h>
#include <AsciiCmd/Texture.h>
#include <AsciiCmd/Transformable.h>


namespace AsciiCmd
{
class Sprite: public Drawable, public Transformable
{
public:

    Sprite(Texture* in=nullptr);
    void SetTexture(Texture* in);
    virtual void Draw(RenderTarget* target);
    Vector2<uint32_t> GetSize(void);

private:
    Texture* tex;

};
}
#endif // SPRITE_H_INCLUDED
