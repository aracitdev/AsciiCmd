#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

namespace AsciiCmd
{
class Event
{
public:


    struct MouseMoveEvent
    {
        uint16_t x,y;
    };

    struct MouseButtonEvent
    {
        enum Button
        {
            Left=0,
            Right,
            Button1,
            Button2,
            Button3,
            Count
        };

        Button code;
    };

    struct TextEvent
    {
        uint32_t character;
    };

    struct KeyEvent
    {
        enum Key
        {
            Unknown=-1,
            A = 0, B, C,
            D, E, F, G,
            H, I, J, K,
            L, M, N, O,
            P, Q, R, S,
            T, U, V, W,
            X, Y, Z, Num0,
            Num1, Num2, Num3, Num4,
            Num5, Num6, Num7, Num8,
            Num9, Escape, LControl, LShift,
            LAlt, LSystem, RControl, RShift,
            RAlt, RSystem, Menu, LBracket,
            RBracket, Semicolon, Comma, Period,
            Quote, Slash, Backslash, Tilde,
            Equal, Hyphen, Space, Enter,
            Backspace, Tab, PageUp, PageDown,
            End, Home, Insert, Delete,
            Add, Subtract, Multiply, Divide,
            Left, Right, Up, Down,
            Numpad0, Numpad1, Numpad2, Numpad3,
            Numpad4, Numpad5, Numpad6, Numpad7,
            Numpad8, Numpad9, F1, F2,
            F3, F4, F5, F6,
            F7, F8, F9, F10,
            F11, F12, F13, F14,
            F15, Pause, KeyCount
        };

        Key code;
        bool alt;
        bool control;
        bool shift;
        bool system;
    };

    enum EventType
    {
        MouseMoved=0,
        MouseButtonPressed,
        MouseButtonReleased,
        KeyPressed,
        KeyReleased,
        TextEntered
    };


    EventType type;
    union
    {
        MouseButtonEvent MouseButton;
        KeyEvent Key;
        MouseMoveEvent MouseMove;
        TextEvent Text;
    };


};

}
#endif // EVENT_H_INCLUDED
