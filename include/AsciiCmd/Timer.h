/**************************************************************************************************
* \file Timer.h
* \brief Defines the timer class.
* \version 1.0
* Defines an stl (chrono) based implementation of a timer.
***************************************************************************************************/

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <chrono>

#include <AsciiCmd/Time.h>
namespace AsciiCmd
{

/**************************************************************************************************
* \class Timer
* A timer class designed to get the time since the timer has last been started.
* Uses the STL implementation (chrono).
***************************************************************************************************/
class Timer
{
public:

/**************************************************************************************************
* \fn Timer()
* Sets up the timer by setting the startTime to the current time, used to get duration.
***************************************************************************************************/
    Timer();

/**************************************************************************************************
* \fn Time GetTime()
* Gets the time elapsed since the start time.
* \return The time elapsed since the last restart in ms.
***************************************************************************************************/
    Time GetTime(void);

/**************************************************************************************************
* \fn void Restart()
* Resets the timer to 0 ms.
***************************************************************************************************/
    void Restart(void);


    void SetTime(uint64_t t);
private:
    std::chrono::high_resolution_clock::time_point startTime; /**< Last time the timer was restarted */
};

}
#endif // TIMER_H_INCLUDED
