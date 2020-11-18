#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <thread>

class Keyboard {
  std::thread t1; 
  
  public:
    Keyboard() = default;
    ~Keyboard() = default;

    char get_key();
};

#endif /*KEYBOARD_H*/
