#include <AsciiCMD/Window.h>
#include <iostream>

#include <windows.h>

namespace AsciiCmd
{

Event::KeyEvent::Key keyTranslations[]=
{
    Event::KeyEvent::Unknown, //VK_LBUTTON
    Event::KeyEvent::Unknown, //VK_RBUTTON
    Event::KeyEvent::Unknown, //VK_CANCEL
    Event::KeyEvent::Unknown, //VK_MBUTTON
    Event::KeyEvent::Unknown, //VK_XBUTTON2
    Event::KeyEvent::Unknown, //VK_XBUTTON2
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Backspace, //VK_BACK
    Event::KeyEvent::Tab, //VK_TAB
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Unknown, //VK_CLEAR
    Event::KeyEvent::Enter, //VK_RETURN
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Unknown, //VK_SHIFT
    Event::KeyEvent::LSystem, //VK_CONTROL
    Event::KeyEvent::LAlt, //VK_MENU
    Event::KeyEvent::Pause, //VK_PAUSE
    Event::KeyEvent::Unknown, //VK_CAPITAL
    Event::KeyEvent::Unknown, //VK_KANA
    Event::KeyEvent::Unknown, //VK_HANGUEL
    Event::KeyEvent::Unknown, //VK_HANGUL
    Event::KeyEvent::Unknown, //VK_IME_ON
    Event::KeyEvent::Unknown, //VK_JUNJA
    Event::KeyEvent::Unknown, //VK_FINAL
    Event::KeyEvent::Unknown, //VK_HANJA
    Event::KeyEvent::Unknown, //VK_KANJI
    Event::KeyEvent::Unknown, //VK_IME_OFF
    Event::KeyEvent::Escape, //VK_ESCAPE
    Event::KeyEvent::Unknown, //VK_CONVERT
    Event::KeyEvent::Unknown, //VK_NONCONVERT
    Event::KeyEvent::Unknown, //VK_ACCEPT
    Event::KeyEvent::Unknown, //VK_MODECHANGE
    Event::KeyEvent::Space,  //VK_SPACE
    Event::KeyEvent::PageUp, //VK_PRIOR
    Event::KeyEvent::PageDown, //VK_NEXT
    Event::KeyEvent::End, //VK_END
    Event::KeyEvent::Home, //VK_HOME
    Event::KeyEvent::Left, //VK_LEFT
    Event::KeyEvent::Up, //VK_UP
    Event::KeyEvent::Right, //VK_RIGHT
    Event::KeyEvent::Down, //VK_DOWN
    Event::KeyEvent::Unknown, //VK_SELECT
    Event::KeyEvent::Unknown, //VK_PRINT
    Event::KeyEvent::Unknown, //VK_EXECUTE
    Event::KeyEvent::Unknown, //VK_SNAPSHOT
    Event::KeyEvent::Insert, //VK_INSERT
    Event::KeyEvent::Delete, //VK_DELETE
    Event::KeyEvent::Unknown, //VK_HELP
    Event::KeyEvent::Num0, //0
    Event::KeyEvent::Num1, //1
    Event::KeyEvent::Num2, //2
    Event::KeyEvent::Num3, //3
    Event::KeyEvent::Num4, //4
    Event::KeyEvent::Num5, //5
    Event::KeyEvent::Num6, //6
    Event::KeyEvent::Num7, //7
    Event::KeyEvent::Num8, //8
    Event::KeyEvent::Num9, //9
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::A,
    Event::KeyEvent::B,
    Event::KeyEvent::C,
    Event::KeyEvent::D,
    Event::KeyEvent::E,
    Event::KeyEvent::F,
    Event::KeyEvent::G,
    Event::KeyEvent::H,
    Event::KeyEvent::I,
    Event::KeyEvent::J,
    Event::KeyEvent::K,
    Event::KeyEvent::L,
    Event::KeyEvent::M,
    Event::KeyEvent::N,
    Event::KeyEvent::O,
    Event::KeyEvent::P,
    Event::KeyEvent::Q,
    Event::KeyEvent::R,
    Event::KeyEvent::S,
    Event::KeyEvent::T,
    Event::KeyEvent::U,
    Event::KeyEvent::V,
    Event::KeyEvent::W,
    Event::KeyEvent::X,
    Event::KeyEvent::Y,
    Event::KeyEvent::Z,
    Event::KeyEvent::Unknown, //VK_LWIN
    Event::KeyEvent::Unknown, //VK_RWIN
    Event::KeyEvent::Unknown, //VK_APPS
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown, //VK_SLEEP
    Event::KeyEvent::Numpad0, //VK_NUMPAD0
    Event::KeyEvent::Numpad1, //VK_NUMPAD1
    Event::KeyEvent::Numpad2, //VK_NUMPAD2
    Event::KeyEvent::Numpad3, //VK_NUMPAD3
    Event::KeyEvent::Numpad4, //VK_NUMPAD4
    Event::KeyEvent::Numpad5, //VK_NUMPAD5
    Event::KeyEvent::Numpad6, //VK_NUMPAD6
    Event::KeyEvent::Numpad7, //VK_NUMPAD7
    Event::KeyEvent::Numpad8, //VK_NUMPAD8
    Event::KeyEvent::Numpad9, //VK_NUMPAD9
    Event::KeyEvent::Multiply, //VK_MULTIPLY
    Event::KeyEvent::Add, //VK_ADD
    Event::KeyEvent::Unknown, //VK_SEPARATOR
    Event::KeyEvent::Subtract, //VK_SUBTRACT
    Event::KeyEvent::Unknown, //VK_DECIMAL
    Event::KeyEvent::Divide, //VK_DIVIDE
    Event::KeyEvent::F1, //VK_F1
    Event::KeyEvent::F2, //VK_F2
    Event::KeyEvent::F3, //VK_F3
    Event::KeyEvent::F4, //VK_F4
    Event::KeyEvent::F5, //VK_F5
    Event::KeyEvent::F6, //VK_F6
    Event::KeyEvent::F7, //VK_F7
    Event::KeyEvent::F8, //VK_F8
    Event::KeyEvent::F9, //VK_F9
    Event::KeyEvent::Unknown, //FK_F10
    Event::KeyEvent::Unknown, //FK_F11
    Event::KeyEvent::Unknown, //FK_F12
    Event::KeyEvent::Unknown, //FK_F13
    Event::KeyEvent::Unknown, //FK_F14
    Event::KeyEvent::Unknown, //FK_F15
    Event::KeyEvent::Unknown, //FK_F16
    Event::KeyEvent::Unknown, //FK_F17
    Event::KeyEvent::Unknown, //FK_F18
    Event::KeyEvent::Unknown, //FK_F19
    Event::KeyEvent::Unknown, //FK_F20
    Event::KeyEvent::Unknown, //FK_F21
    Event::KeyEvent::Unknown, //FK_F22
    Event::KeyEvent::Unknown, //FK_F23
    Event::KeyEvent::Unknown, //FK_F24
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown, //VK_NUMLOCK
    Event::KeyEvent::Unknown, //VK_SCROLL
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::LShift, //VK_LSHIFT
    Event::KeyEvent::RShift, //VK_RSHIFT
    Event::KeyEvent::LControl, //VK_LCONTROL
    Event::KeyEvent::RControl, //VK_RCONTROL
    Event::KeyEvent::Unknown, //VK_LMENU
    Event::KeyEvent::Unknown, //VK_RMENU
    Event::KeyEvent::Unknown, //VK_BROWSER_BACK
    Event::KeyEvent::Unknown,//VK_BROWSER_FORWARD
    Event::KeyEvent::Unknown, //VK_BROWSER_REFRESH
    Event::KeyEvent::Unknown, //VK_BROWSER_STOP
    Event::KeyEvent::Unknown, //VK_BROWSER_SEARCH
    Event::KeyEvent::Unknown, //VK_BROWSER_FAVORITES
    Event::KeyEvent::Unknown, //VK_BROWSER_HOME
    Event::KeyEvent::Unknown, //VK_VOLUME_MUTE
    Event::KeyEvent::Unknown, //VK_VOLUME_DOWN
    Event::KeyEvent::Unknown, //VK_VOLUME_UP
    Event::KeyEvent::Unknown, //VK_MEDIA_NEXT_TRACK
    Event::KeyEvent::Unknown, //VK_MEDIA_PREV_TRACK
    Event::KeyEvent::Unknown, //VK_MEDIA_STOP
    Event::KeyEvent::Unknown, //VK_MEDIA_PLAY_PAUSE
    Event::KeyEvent::Unknown, //VK_LAUNCH_MAIL
    Event::KeyEvent::Unknown, //VK_LAUNCH_MEDIA_SELECT
    Event::KeyEvent::Unknown, //VK_LAUNCH_APP1
    Event::KeyEvent::Unknown, //VK_LAUNCH_APP2
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Unknown, //
    Event::KeyEvent::Semicolon, //VK_OEM_1
    Event::KeyEvent::Equal, //VK_OEM_PLUS
    Event::KeyEvent::Comma, //VK_OEM_COMMA
    Event::KeyEvent::Hyphen, //VK_OEM_MINUS
    Event::KeyEvent::Period, //VK_OEM_PERIOD
    Event::KeyEvent::Slash, //VK_OEM_2
    Event::KeyEvent::Tilde, //VK_OEM_3
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::LBracket, //VK_OEM_4
    Event::KeyEvent::Backslash, //VK_OEM_5
    Event::KeyEvent::RBracket, //VK_OEM_6
    Event::KeyEvent::Quote, //VK_OEM_7
    Event::KeyEvent::Unknown, //VK_OEM_8
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown, //VK_PROCESS_KEY
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown, //VK_PACKET
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown,
    Event::KeyEvent::Unknown, //VK_ATTN
    Event::KeyEvent::Unknown, //VK_CRSL
    Event::KeyEvent::Unknown, //VK_EXSEL
    Event::KeyEvent::Unknown, //VK_EREOF
    Event::KeyEvent::Unknown, //VK_PLAY
    Event::KeyEvent::Unknown, //VK_ZOOM
    Event::KeyEvent::Unknown, //VK_NONAME
    Event::KeyEvent::Unknown, //VK_PA1
    Event::KeyEvent::Unknown //VK_OEM_CLEAR
};


Window::Window(Vector2<uint16_t> windowSize, std::string title)
{
    eventCacheCount=0;
    SetupInput();
    windowBuffer=nullptr;
    Resize(windowSize);
    SetTitle(title);
    currentColor=0x0f;
    open=true;
}

Window::Window(Vector2<uint16_t> windowSize)
{
    eventCacheCount=0;
    SetupInput();
    windowBuffer=nullptr;
    Resize(windowSize);
    currentColor=0x0f;
    open=true;
}

Window::Window()
{
    eventCacheCount=0;
    SetupInput();
    windowBuffer=nullptr;
    currentColor=0x0f;
    open=true;
}

Window::~Window()
{
    DestroyInput();
    if(windowBuffer)
        delete[] windowBuffer;
}


void Window::SetupInput(void)
{
    stdIn=GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(stdIn, &oldMode);

    DWORD currentMode = ENABLE_EXTENDED_FLAGS;  //disable quick edit mode
    SetConsoleMode(stdIn, currentMode);

    currentMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(stdIn, currentMode);
    for(uint32_t counter=0; counter < sizeof(mouseButtonStates); counter++)
        mouseButtonStates[counter]=false;
    for(uint32_t counter=0; counter < sizeof(keyboardStates); counter++)
        keyboardStates[counter]=false;
    inputRecordCache=new INPUT_RECORD[5];
}

void Window::DestroyInput(void)
{
    SetConsoleMode(stdIn, oldMode);
    delete[] inputRecordCache;
}


bool Window::IsEventAvaliable(void)
{
    DWORD eventCount;
    GetNumberOfConsoleInputEvents(stdIn, &eventCount);
    return eventCount || eventCacheCount;
}

bool Window::PollEvents(Event& event)
{
    if(eventCacheCount) //do this so we don't have a backup of events
    {
        event=eventCache[eventCacheCount-1];
        eventCacheCount--;
        return true;
    }

    DWORD eventCount=1;
    while(eventCount)
    {
        GetNumberOfConsoleInputEvents(stdIn, &eventCount);
        if(eventCount > 0)
        {
            DWORD eventsRead;
            ReadConsoleInput(stdIn, inputRecordCache, 1, &eventsRead);
            HandleEvent(inputRecordCache[0]);
        }
    }

    if(eventCacheCount) //do this so we don't have a backup of events
    {
        event=eventCache[eventCacheCount-1];
        eventCacheCount--;
        return true;
    }

    return false;
}

void Window::AddEvent(Event ev)
{
    if(eventCacheCount +1 >= sizeof(eventCache))
        return;
    eventCacheCount++;
    eventCache[eventCacheCount-1]=ev;
}

void Window::HandleEvent(INPUT_RECORD in)
{
    switch(in.EventType)
    {
    case MOUSE_EVENT:
        for(uint8_t counter=0; counter < sizeof(mouseButtonStates); counter++)
            if((in.Event.MouseEvent.dwButtonState & (1<<counter)) != mouseButtonStates[counter])
            {
                Event event;
                mouseButtonStates[counter] = in.Event.MouseEvent.dwButtonState & (1<<counter);
                event.MouseButton.code = (Event::MouseButtonEvent::Button)counter;
                event.type = (mouseButtonStates[counter] ? Event::MouseButtonPressed : Event::MouseButtonReleased);
                AddEvent(event);
            }

        if(Vector2<uint16_t>(in.Event.MouseEvent.dwMousePosition.X, in.Event.MouseEvent.dwMousePosition.Y) != mousePos)
        {
            Event event;
            event.type = Event::MouseMoved;
            event.MouseMove.x=in.Event.MouseEvent.dwMousePosition.X;
            event.MouseMove.y=in.Event.MouseEvent.dwMousePosition.Y;
            mousePos=Vector2<uint16_t>(in.Event.MouseEvent.dwMousePosition.X,in.Event.MouseEvent.dwMousePosition.Y);
            AddEvent(event);
        }
        break;
    case KEY_EVENT:
        Event event;
        event.type = in.Event.KeyEvent.bKeyDown ? Event::KeyPressed : Event::KeyReleased;
        event.Key.code = keyTranslations[in.Event.KeyEvent.wVirtualKeyCode];
        event.Key.alt = in.Event.KeyEvent.dwControlKeyState & 2 || in.Event.KeyEvent.dwControlKeyState & 1;
        event.Key.control = in.Event.KeyEvent.dwControlKeyState & 8 || in.Event.KeyEvent.dwControlKeyState & 4;
        event.Key.shift = in.Event.KeyEvent.dwControlKeyState & 0x10;
        event.Key.system = false;
        AddEvent(event);

        if(in.Event.KeyEvent.uChar.UnicodeChar)
        {
            Event textEvent;
            textEvent.Text.character= in.Event.KeyEvent.uChar.UnicodeChar;
            textEvent.type= Event::TextEntered;
            AddEvent(textEvent);
        }
        break;
    }
}


bool Window::IsPressed(Event::MouseButtonEvent::Button button)
{
    return mouseButtonStates[button];
}

bool Window::IsPressed(Event::KeyEvent::Key key)
{
    return keyboardStates[key];
}

Vector2<uint16_t> Window::GetMousePos(void)
{
    return mousePos;
}

void Window::Close(void)
{
    open=false;
}

bool Window::IsOpen(void)
{
    return open;
}

void Window::SetTitle(const std::string& newTitle)
{
    SetConsoleTitle((LPCSTR)newTitle.c_str());
}

void Window::Resize(Vector2<uint16_t> windowSize)
{
    if(windowBuffer)
    {
        delete[] windowBuffer;
        windowBuffer=nullptr;
    }
    size=windowSize;
    if(size.x && size.y)
    {
        windowBuffer = new CHAR_INFO[size.x * size.y];
        FitTerminalSize();
    }
}

void Window::Display(void)
{
    if(!windowBuffer)
        return;
    COORD dwBufferSize = { (short)size.x, (short)size.y };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, (short)size.x, (short)size.y };
    HANDLE hOutput = (HANDLE)GetStdHandle( STD_OUTPUT_HANDLE );
    WriteConsoleOutput( hOutput, windowBuffer, dwBufferSize,
    dwBufferCoord, &rcRegion );
}

void Window::PutPixel(Vector2<int32_t> pos, uint32_t character, int color)
{
    if(!windowBuffer || character == '\0')
        return;
    if(pos.x >= 0 && pos.y >= 0 && pos.x < size.x && pos.y < size.y)
    {
        windowBuffer[pos.y * size.x + pos.x].Char.UnicodeChar=character;
        windowBuffer[pos.y * size.x + pos.x].Attributes=color;
    }
}

void Window::SetPixel(Vector2<int32_t> pos, char c, int color)
{
    PutPixel(pos, c,color);
}

void Window::FitTerminalSize(void)
{
    COORD sz={(short)size.x, (short)size.y};
    SMALL_RECT const minimalWindow = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(windowBuffer, TRUE, &minimalWindow);
    SetConsoleScreenBufferSize(windowBuffer, sz);
    SMALL_RECT const window = { 0, 0,(short)(((short)size.x) - 1), (short)(((short)size.y) - 1) };
    SetConsoleWindowInfo(windowBuffer, TRUE, &window);
}

void Window::Draw(Drawable& object)
{
    if(!windowBuffer)
        return;
    object.Draw(this);
}

void Window::Clear(uint32_t character, int color)
{
    Vector2<uint32_t> pos;
    for(pos.y=0; pos.y < size.y; pos.y++)
        for(pos.x=0; pos.x < size.x; pos.x++)
        PutPixel(pos, character, color);
}

void Window::Clear(void)
{
    Clear(' ',0x0f);
}



void Window::SetStreamColor(int color)
{
    currentColor = color;
}

void Window::SetCursorPos(Vector2<uint16_t> pos)
{
    cursorPos=pos;
}

Window& Window::operator<<(const std::string& in)
{
    for(uint32_t counter=0; counter < in.size(); counter++)
        (*this)<<in[counter];
    return (*this);
}

Window& Window::operator<<(char in)
{
    if(in == '\n')
    {
        cursorPos.y=(cursorPos.y+1)%size.y;
        cursorPos.x=0;
        return (*this);
    }
    PutPixel(cursorPos, in, currentColor);
    cursorPos.x++;
    if(cursorPos.x >= size.x)
    {
        cursorPos.x=0;
        cursorPos.y++;
        if(cursorPos.y >=size.y)
            cursorPos.y=0;
    }
    return *this;
}

}
