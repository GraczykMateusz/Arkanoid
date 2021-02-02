#include <iostream>
#include <ncurses.h>
#include <thread>

#include "Keyboard.h"

Keyboard::Keyboard() {
    //std::thread t1(checkPressedKey, "keyThread");
}

void Keyboard::checkPressedKey() {
    while (true)
    {
        timeout(-1);
        pressedKey = getch();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
