#include <AsciiCmd/Time.h>

namespace AsciiCmd
{


    Time::Time()
    {
        internalTime=std::chrono::microseconds::zero();
    }

    float Time::AsSeconds(void)
    {
        return ((float)internalTime.count())/1000000.0f;
    }

    uint32_t Time::AsMilliseconds(void)
    {
        return internalTime.count() / 1000;
    }

    uint64_t Time::AsMicroseconds(void)
    {
        return internalTime.count();
    }


    Time Time::operator+(const Time& in)
    {
        return Time(in.internalTime + internalTime);
    }

    Time Time::operator-(const Time& in)
    {
        return Time(internalTime - in.internalTime);
    }

    Time Time::operator*(float v)
    {
        return Microseconds(v * internalTime.count());
    }

    Time Time::operator/(float v)
    {
        return Microseconds(internalTime.count() / v);
    }

    Time::Time(std::chrono::microseconds t)
    {
        internalTime=t;
    }

    Time Seconds(float in)
    {
        return Time(std::chrono::microseconds((uint64_t)(in * 1000000)) );
    }

    Time Milliseconds(uint32_t in)
    {
        return Time(std::chrono::microseconds(in * 1000));
    }

    Time Microseconds(uint64_t in)
    {
        return Time(std::chrono::microseconds(in));
    }



    bool Time::operator==(const Time& in)
    {
        return in.internalTime == internalTime;
    }

    bool Time::operator!=(const Time& in)
    {
        return in.internalTime != internalTime;
    }

    bool Time::operator<=(const Time& in)
    {
        return internalTime <= in.internalTime;
    }

    bool Time::operator<(const Time& in)
    {
        return internalTime < in.internalTime;
    }

    bool Time::operator>=(const Time& in)
    {
        return internalTime >= in.internalTime;
    }

    bool Time::operator>(const Time& in)
    {
        return internalTime > in.internalTime;
    }

}
