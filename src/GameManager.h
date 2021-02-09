#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <thread>
#include <ncurses.h>

class GameManager {
  /*All game management, settings etc.*/
  private:
    //Exit
    bool isExit = false;

    //Gameover, win
    bool isGameOver = false;
    bool isWin = false;

    //Points
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
    void checkWin();
};
#endif /*GAME_MANAGER_H*/
