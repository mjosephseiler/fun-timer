#include "Doer.h"
#include <iostream>

void Doer::Do()
{
    std::cout << "Doer doing stuff" << std::endl;
}

void Doer::DoItAgain(int times)
{
    for(int y = 0; y < times; y++)
    {
        std::cout << "Doer doing stuff: " << y << std::endl;
    }
}
