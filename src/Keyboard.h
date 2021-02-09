#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>
#include <thread>

class Keyboard {
  /*The class is responsible for a key input*/
  private:
    int pressedKey;
    bool isRunning = true;

    std::vector<std::thread> vec_t1;  
  
  public:
    //Constructor and destuctor
    Keyboard();
    ~Keyboard() = default;

    //Make thread free
    void stopThread();

    //Check when key is pressed and get that key
    void checkPressedKey();

    //Getters
    int& getPressedKey();
    std::vector<std::thread>& getThread();
};
#endif /*KEYBOARD_H*/
