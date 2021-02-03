#define X 40
#define Y 25

#include "GameManager.h"
#include "Keyboard.h"
#include "Platform.h"
#include "Map.h"

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
  //std::unique_ptr<Keyboard> kb = std::make_unique<Keyboard>();
  std::unique_ptr<Map> map = std::make_unique<Map>(X,Y);
  std::unique_ptr<Platform> platform = std::make_unique<Platform>(X);
  
  //map->startTimer(); 

  map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());

  map->display();
 
  do {
    //map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());

    //map->display();
    //int c = 52;

    //map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
    //platform->moveLeft();
    //map->display();

    /*if(c == 52)
    {

      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveLeft();
    }
    if(c == 54) {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveRight();
    }
    if(c == 27) {
      setExit(true);
    }*/
  } while(!getExit());
  //kb->getThread()[0].join();
};
