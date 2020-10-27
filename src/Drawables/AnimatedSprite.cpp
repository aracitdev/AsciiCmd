#include <AsciiCmd/Drawables/AnimatedSprite.h>


namespace AsciiCmd
{


void AnimatedSprite::Draw(RenderTarget* target)
{
    if(anim)
        SetTexture(&(anim->GetCurrentFrame()));
    Sprite::Draw(target);
}

void AnimatedSprite::SetAnimation(Animation* newAnim)
{
    anim=newAnim;
    if(!anim)
        SetTexture(nullptr);
}


}
