#define MAP_WIDTH 40
#define MAP_HIGHT 25

#define POINTS_COUNT 24
#define WIN_POINTS 15

#define NUMERIC_4 52
#define NUMERIC_6 54
#define ESC 27

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

void GameManager::reset() {
  isExit = false;
  isGameOver = false;
  isWin = false;
  pointsCount = 0;
}

void GameManager::checkWin() {
  if(pointsCount == WIN_POINTS) {
    isWin = true;
  }
}

void GameManager::startGame() {
  reset();
  
  std::unique_ptr<Keyboard> kb = std::make_unique<Keyboard>();
  std::unique_ptr<Map> map = std::make_unique<Map>(MAP_WIDTH, MAP_HIGHT);
  std::unique_ptr<Platform> platform = std::make_unique<Platform>(MAP_WIDTH, MAP_HIGHT);
  std::unique_ptr<Ball> ball = std::make_unique<Ball>(MAP_WIDTH, MAP_HIGHT);

  std::vector<std::shared_ptr<Point>> points;

  for(unsigned int i = 0; i < POINTS_COUNT; ++i) {
    std::shared_ptr<Point> point = std::make_shared<Point>(i);
    points.push_back(point);
  }
 
  map->controlHelp();

  map->startTimer();

  do {
    map->setPoints(points);
    map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
    map->setBall(ball->getBallChar(), ball->getPositionX(), ball->getPositionY());

    map->display();

    map->removeBall(ball->getPositionX(), ball->getPositionY());

    if(ball->isPointCollision(map->getMapFields())) {
      ball->moveIfPointCollision(map->getMapFields(), points, pointsCount);
      map->removePoint(points, ball->getHitPointPositionX(), ball->getHitPointPositionY());
    } else {
      ball->move(map->getMapFields(), MAP_WIDTH, MAP_HIGHT, isGameOver);
    }
    
    if(ball->getMoveException()){
      ball->move(map->getMapFields(), MAP_WIDTH, MAP_HIGHT, isGameOver);
    }

    if(kb->getPressedKey() == NUMERIC_4)
    {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveLeft();
    }
    if(kb->getPressedKey() == NUMERIC_6) {
      map->removePlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
      platform->moveRight();
    }
    if(kb->getPressedKey() == ESC) {
      isExit = true;
    }
  } while(!isExit && !isGameOver && !isWin);

  if(isGameOver) {
    map->displayGameOver(pointsCount);
  }

  if(isWin) {
    map->displayWin(pointsCount);
  }

  kb->stopThread();
  clear();
};