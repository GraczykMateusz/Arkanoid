#include "Keyboard.h"
#include <iostream>

const std::string Keyboard::checkPressedKey() {
    pressedKey = getchar();
    return pressedKey;
}
