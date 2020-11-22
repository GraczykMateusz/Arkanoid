#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>

class Keyboard {
  std::string pressedKey;
  public:
    Keyboard() = default;
    ~Keyboard() = default;

    const std::string checkPressedKey();
};

#endif /*KEYBOARD_H*/
