#include <iostream>
#include "Timer.h"
#include "Doer.h"
#include <thread>

void DoStuff()
{
    std::cout << "Free function doing stuff now" << std::endl;
}

int main()
{
    std::cout << "I am a running program" << std::endl;

    std::cout << "Create timer with free function" << std::endl;
    Timer timer1(DoStuff);
    timer1.Start(5000, 1000); // wait 5 seconds, do stuff at 1 second intervals
    std::this_thread::sleep_for(std::chrono::milliseconds(20000)); // wait to stop timer
    timer1.Stop();

    Doer doer;
    std::cout << "Create a timer with member function" << std::endl;
    Timer timer2(std::bind(&Doer::Do, &doer));
    timer2.Start(10000, 1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    timer2.Stop();

    std::cout << "Create a timer with member function having an integer parameter" << std::endl;
    Timer timer3(std::bind(&Doer::DoItAgain, &doer, 5)); 
    timer3.Start(10000, 1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    timer3.Stop();

    std::cout << "Program exiting" << std::endl;

    return(0);
}
