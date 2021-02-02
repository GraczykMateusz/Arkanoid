#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>

class Keyboard {
  int pressedKey;
  public:
    Keyboard();
    ~Keyboard() = default;

    void checkPressedKey();
    int getPressedKey() const { return pressedKey; }
};

#endif /*KEYBOARD_H*/
