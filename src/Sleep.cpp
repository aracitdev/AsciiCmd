#include <AsciiCmd/Sleep.h>
#include <thread>

namespace AsciiCmd
{
    void Sleep(Time time)
    {
        std::this_thread::sleep_for(time.internalTime);
    }
}
