#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <memory>
#include <thread>
#include <ncurses.h>

class GameManager {
  bool isExit = false;

  public:
    GameManager() = default;
    ~GameManager() = default;

    void menu();
    unsigned int input();
    void startGame();

    void setExit(bool exit) { this->isExit = exit; }
    const bool getExit() const { return isExit; } 
};
#endif /*GameManager.h*/
