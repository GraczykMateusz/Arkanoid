#include <iostream>
#include <memory>
#include <ncurses.h>

#include "GameManager.h"

int main() {
  initscr();
  noecho();
  std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
  
  while(true) {
    gameManager->menu();  
    switch(gameManager->input()) {
      case 1:
        gameManager->startGame();
        break;
      case 2:
        endwin();
        return 0;
        break;
      default:
        break;
    }
  }
}
