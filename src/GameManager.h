#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
  public:
    GameManager() = default;
    ~GameManager() = default;

    void menu();
    unsigned int input();
    void startGame();
};
#endif /*GameManager.h*/
