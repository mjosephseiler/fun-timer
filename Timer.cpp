#include "Timer.h"
#include <thread>
#include <chrono>

Timer::Timer(std::function<void()> func) :
   triggerFunc(func),
   stop(false),
   running(false)
{
}

Timer::~Timer()
{
    Stop();
}

void Timer::Start(unsigned long initialWait, unsigned long interval)
{
    if(running)
    {
        throw std::bad_function_call();
    }
    running = true;
    auto funk = [&] (unsigned long initialWait, unsigned long interval) 
    {
        auto t_start = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds delay(initialWait);
        while(!stop)
        {
            auto t_now = std::chrono::high_resolution_clock::now();
            std::chrono::milliseconds elapsed = 
                std::chrono::duration_cast<std::chrono::milliseconds>(t_now - t_start);
            if(elapsed >= delay)
            {
                triggerFunc();
                t_start = t_now;
                delay = std::chrono::milliseconds(interval);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    };
    std::thread t1 = std::thread(funk, initialWait, interval);
    t1.detach();
}

void Timer::Stop()
{
    stop = true;
}
