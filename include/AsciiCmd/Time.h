#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <cstdint>
#include <chrono>

namespace AsciiCmd
{

class Time
{
public:
    Time();
    float AsSeconds(void);
    uint32_t AsMilliseconds(void);
    uint64_t AsMicroseconds(void);

    friend class Timer;
    friend Time Seconds(float);
    friend Time Milliseconds(uint32_t);
    friend Time Microseconds(uint64_t);
    friend void Sleep(Time);

    Time operator+(const Time& in);
    Time operator-(const Time& in);
    Time operator*(float v);
    Time operator/(float v);


    bool operator==(const Time& in);
    bool operator!=(const Time& in);
    bool operator<=(const Time& in);
    bool operator<(const Time& in);
    bool operator>=(const Time& in);
    bool operator>(const Time& in);
protected:
    Time(std::chrono::microseconds);
private:
    std::chrono::microseconds internalTime;
};

Time Seconds(float);
Time Milliseconds(uint32_t);
Time Microseconds(uint64_t);

}

#endif // TIME_H_INCLUDED
