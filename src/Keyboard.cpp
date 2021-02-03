#include "Keyboard.h"

Keyboard::Keyboard() {
    try
    {
        vec_t1.push_back(std::thread(&Keyboard::checkPressedKey, this));
    }
    catch(const std::exception& e)
    {
        printw(e.what());
    }
}

void Keyboard::checkPressedKey() {
    while (isRunning)
    {
        timeout(-1);
        pressedKey = getch();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Keyboard::stopThread() {
    isRunning = false;
    vec_t1[0].join();
}
