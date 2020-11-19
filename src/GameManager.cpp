#define X 40
#define Y 25

#include <iostream>
#include <memory>

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

  std::cout << "Select: ";
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
  std::unique_ptr<Platform> platform = std::make_unique<Platform>();

  //map->startTimer(); 
  //map->display();

  map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());

  int stop;
  std::cin >> stop; 

  system("PAUSE");
};
