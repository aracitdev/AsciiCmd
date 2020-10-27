#include <iostream>
#include <AsciiCmd/Window.h>
#include <AsciiCmd/Drawables/Sprite.h>
#include <AsciiCmd/Texture.h>
#include <AsciiCmd/Sleep.h>
#include <AsciiCmd/Palette.h>
#include <AsciiCmd/Drawables/Rectangle.h>
#include <ASciiCmd/Drawables/AnimatedSprite.h>

int main()
{
    AsciiCmd::Animation Anim;
    Anim.LoadFromFile("out.ascii");
    Anim.RemoveFrame(0);
    AsciiCmd::AnimatedSprite spr;
    spr.SetAnimation(&Anim);

    AsciiCmd::Palette palette(AsciiCmd::Palette::defaultPalette, Vector2<uint16_t>(6,6));
    palette.SwapPallete();

    AsciiCmd::Window testWindow(Vector2<uint16_t>(100,180),"test");

    while(testWindow.IsOpen())
    {
        AsciiCmd::Event event;
        while(testWindow.PollEvents(event))
        {
            if(event.type == AsciiCmd::Event::MouseButtonPressed)
            {
                Anim.SetPlaying(!Anim.IsPlaying());
            }
        }

        testWindow.Clear();
        testWindow.Draw(spr);
        testWindow.SetPixel(testWindow.GetMousePos(), '*', 0x0f);
        testWindow.Display();
    }

    return 0;
}
