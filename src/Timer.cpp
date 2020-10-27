#include <AsciiCmd/Timer.h>


namespace AsciiCmd
{

Timer::Timer()
{
    Restart();
}

void Timer::Restart(void)
{
    startTime=std::chrono::high_resolution_clock::now();
}

Time Timer::GetTime(void)
{
    return Time(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startTime));
}

void Timer::SetTime(uint64_t t)
{
    startTime=std::chrono::high_resolution_clock::now() - std::chrono::milliseconds(t);
}

}
