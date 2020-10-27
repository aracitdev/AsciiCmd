#ifndef ANIMATEDSPRITE_H_INCLUDED
#define ANIMATEDSPRITE_H_INCLUDED
#include <AsciiCmd/Drawables/Sprite.h>
#include <AsciiCmd/Animation.h>

namespace AsciiCmd
{
class AnimatedSprite: public Sprite
{
public:

    void SetAnimation(Animation* newAnim);
    virtual void Draw(RenderTarget* target);

private:
    Animation* anim;
};
}
#endif // ANIMATEDSPRITE_H_INCLUDED
