#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <memory>
#include <thread>
#include <ncurses.h>

class GameManager {
  bool exit = false;

  public:
    GameManager() = default;
    ~GameManager() = default;

    void menu();
    unsigned int input();
    void startGame();

    void setExit(bool exit) { this->exit = exit; }
    const bool getExit() const { return exit; } 
};
#endif /*GameManager.h*/
