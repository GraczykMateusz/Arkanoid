#define X 40
#define Y 24

#include "GameManager.h"
#include "Keyboard.h"
#include "Platform.h"
#include "Map.h"
#include "Ball.h"
#include "Point.h"

void GameManager::menu() {
  printw("The Arkanoid Game\n"); 
  printw("1. Start\n");
  printw("2. Exit\n");
}

unsigned int GameManager::input() {
  std::string sInput;
  char cInput;

  printw("Select: ");

  sInput = getch();

  try {
    cInput = std::stoi(sInput);
  } catch(std::exception e) {
    return -1;
  }
  return cInput;
}

void GameManager::startGame() {
  std::unique_ptr<Keyboard> kb = std::make_unique<Keyboard>();
  std::unique_ptr<Map> map = std::make_unique<Map>(X,Y);
  std::unique_ptr<Platform> platform = std::make_unique<Platform>(X);
  std::unique_ptr<Ball> ball = std::make_unique<Ball>(X,Y);
  
  setExit(false);
 
  //map->controlHelp();

  do {
    map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
    map->setBall(ball->getBallChar(), ball->getPositionX(), ball->getPositionY());

    map->display();

    map->removeBall(ball->getPositionX(), ball->getPositionY());
    ball->move(map->getMapFields(), X, Y);

    if(kb->getPressedKey() == 52)
    {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveLeft();
    }
    if(kb->getPressedKey() == 54) {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveRight();
    }
    if(kb->getPressedKey() == 27) {
      setExit(true);
    }
  } while(!getExit());

  kb->stopThread();
  clear();
};
