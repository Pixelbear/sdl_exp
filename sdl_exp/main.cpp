#include "Visualisation.h"
#include <stdio.h>

int main()
{
    Visualisation v = Visualisation("Visulisation Example", 1280, 720);
    v.setRenderAxis(true);
    v.runAsync();

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

