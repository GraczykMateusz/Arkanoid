#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <thread>
#include <ncurses.h>

class GameManager {
  //Exit
  bool isExit = false;

  public:
    //Constructor and destuctor
    GameManager() = default;
    ~GameManager() = default;

    //Methods
    void menu();
    unsigned int input();
    void startGame();

    //Exit
    void setExit(bool exit) { this->isExit = exit; }
    const bool getExit() const { return isExit; } 
};
#endif /*GAME_MANAGER_H*/
