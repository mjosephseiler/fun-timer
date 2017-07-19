#ifndef TIMER_H_
#define TIMER_H_

#include <functional>
#include <atomic>

class Timer
{
    public:
        Timer(std::function<void()> func);
        ~Timer();
        void Start(unsigned long initialWait, unsigned long interval);
        void Stop();

    private:
        std::function<void()> triggerFunc;
        std::atomic<bool> stop;
        std::atomic<bool> running;
};

#endif /* TIMER_H_ */
