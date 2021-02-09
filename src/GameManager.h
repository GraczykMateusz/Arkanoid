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

    //Settings
    bool isControlHelp = true;
    bool isTimer = true;

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

    //Settings
    void helpOffOn();
    void timerOffOn();
};
#endif /*GAME_MANAGER_H*/
