#include <iostream>
#include <memory>
#include <ncurses.h>

#include "GameManager.h"

int main() {
  initscr();
  noecho();
  std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
  
  while(true) {
    clear();
    gameManager->menu();  
    switch(gameManager->input()) {
      case 1:
        gameManager->startGame();
        break;
      case 2:
        gameManager->helpOffOn();
        break;
      case 3:
        gameManager->timerOffOn();
        break;
      case 4:
        endwin();
        return 0;
        break;
      default:
        break;
    }
  }
}
