#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

namespace AsciiCmd
{
class RenderTarget;
class Drawable
{
public:

    virtual void Draw(RenderTarget* target)=0;

protected:
};
}
#endif // DRAWABLE_H_INCLUDED
