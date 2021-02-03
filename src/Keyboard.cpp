#include "Keyboard.h"

Keyboard::Keyboard() {
    try
    {
        //std::thread t1([this] {this->checkPressedKey(); });
        some_threads.push_back(std::thread(&Keyboard::checkPressedKey, this));
    }
    catch(const std::exception& e)
    {
        
    }
}

void Keyboard::checkPressedKey() {
    while (true)
    {
        //timeout(-1);
        pressedKey = getch();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
