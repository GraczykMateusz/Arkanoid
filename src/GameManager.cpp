#define X 40
#define Y 25

#include <iostream>
#include <memory>
#include <thread>

#include "GameManager.h"
#include "Keyboard.h"
#include "Platform.h"
#include "Map.h"

void GameManager::menu() {
  system("stty cooked");
  std::cout << "The Arkanoid Game" << std::endl; 
  std::cout << "1. Start\n";
  std::cout << "2. Exit\n";
  system("stty raw");
}

unsigned int GameManager::input() {
  std::string sInput;
  char cInput;

  system("stty cooked");
  std::cout << "Select: ";
  system("stty raw");

  sInput = getchar();

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
  
  map->startTimer(); 

  map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());

  map->display();
 
  do {
    map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());

    map->display();
    
    if(kb->checkPressedKey() == "4")
    {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveLeft();
    }
    if(kb->checkPressedKey() == "6") {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveRight();
    }
  } while(true);
  //int stop;
  //std::cin >> stop; 

  //system("PAUSE");
};
