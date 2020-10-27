#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <AsciiCMD/Vector2.h>
#include <cstdint>
#include <string>
#include <AsciiCMD/RenderTarget.h>
#include <AsciiCMD/Drawables/Drawable.h>
#include <AsciiCMD/Event.h>

typedef struct _CHAR_INFO CHAR_INFO;
typedef struct _INPUT_RECORD INPUT_RECORD;

namespace AsciiCmd
{

class Window: public RenderTarget
{
public:

    Window(Vector2<uint16_t> windowSize, std::string title);
    Window(Vector2<uint16_t> windowSize);
    Window();
    ~Window();

    bool IsEventAvaliable(void);
    bool PollEvents(Event& event);

    void SetPixel(Vector2<int32_t> pos, char c, int color);
    void Resize(Vector2<uint16_t> windowSize);
    void Display(void);
    virtual void Draw(Drawable& object);
    void Clear(uint32_t character, int color);
    void Clear(void);
    void SetTitle(const std::string& newTitle);
    Vector2<uint16_t> GetSize(void);

    Vector2<uint16_t> GetMousePos(void);

    void SetStreamColor(int color);
    void SetCursorPos(Vector2<uint16_t> pos);
    Window& operator<<(const std::string& in);
    Window& operator<<(char in);
    bool IsOpen(void);
    void Close(void);

    bool IsPressed(Event::MouseButtonEvent::Button);
    bool IsPressed(Event::KeyEvent::Key);
protected:
    virtual void PutPixel(Vector2<int32_t> pos, uint32_t character, int color);
    int currentColor;
    Vector2<uint16_t> cursorPos;

    void* stdIn;
    long unsigned int oldMode;
    void SetupInput(void);
    void DestroyInput(void);
    void HandleEvent(INPUT_RECORD in);
    bool open;

    Event eventCache[20];
    size_t eventCacheCount;
    INPUT_RECORD* inputRecordCache;

    Vector2<uint16_t> mousePos;
    bool mouseButtonStates[Event::MouseButtonEvent::Count];
    bool keyboardStates[Event::KeyEvent::KeyCount];

    void FitTerminalSize(void);
    void MaximizeWindow(void);
    CHAR_INFO* windowBuffer;
    Vector2<uint16_t> size;

    void AddEvent(Event ev);
};

}

#endif // WINDOW_H_INCLUDED
