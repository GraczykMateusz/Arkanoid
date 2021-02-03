#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>
#include <thread>

class Keyboard {
  int pressedKey = 52;
  bool isRunning = true;

  std::vector<std::thread> some_threads;  
  
  public:
    Keyboard();
    ~Keyboard() = default;

    void stopThread();

    void checkPressedKey();
    int& getPressedKey() { return pressedKey; }
    std::vector<std::thread>& getThread() { return some_threads; }
};

#endif /*KEYBOARD_H*/
