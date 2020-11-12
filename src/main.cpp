#include <iostream>
#include <memory>

#include "GameManager.h"
#include "systemClear.h"

int main() {
  system("stty raw");
  std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
  
  while(true) {
    systemClear();
    gameManager->menu();  
    switch(gameManager->input()) {
      case 1:
        gameManager->startGame();
        break;
      case 2:
        system("stty cooked");
        return 0;
        break;
      default:
        break;
    }
  }
}
