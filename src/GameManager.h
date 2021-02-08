#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <thread>
#include <ncurses.h>

class GameManager {
  //Exit
  bool isExit = false;
  bool isGameOver = false;
  unsigned int pointsCount = 0;

  public:
    //Constructor and destuctor
    GameManager() = default;
    ~GameManager() = default;

    //Methods
    void menu();
    unsigned int input();
    void startGame();
    void reset();
};
#endif /*GAME_MANAGER_H*/
