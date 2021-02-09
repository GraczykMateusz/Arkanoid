#define X 40
#define Y 25
#define POINTS_COUNT 24

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
  pointsCount = 0;
}

void GameManager::startGame() {
  reset();
  
  std::unique_ptr<Keyboard> kb = std::make_unique<Keyboard>();
  std::unique_ptr<Map> map = std::make_unique<Map>(X,Y);
  std::unique_ptr<Platform> platform = std::make_unique<Platform>(X,Y);
  std::unique_ptr<Ball> ball = std::make_unique<Ball>(X,Y);

  std::vector<std::shared_ptr<Point>> points;

  for(unsigned int i = 0; i < POINTS_COUNT; ++i) {
    std::shared_ptr<Point> point = std::make_shared<Point>(i);
    points.push_back(point);
  }
 
  //map->controlHelp();

  //map->startTimer();

  do {
    map->setPoints(points);
    map->setPlatform(platform->getPlatform(), platform->getPositionX(), platform->getPositionY());
    map->setBall(ball->getBallChar(), ball->getPositionX(), ball->getPositionY());

    map->display();
    //auto c = getch();
    map->removeBall(ball->getPositionX(), ball->getPositionY());

    if(ball->isPointCollision(map->getMapFields())) {
      ball->moveIfPointCollision(map->getMapFields(), points, pointsCount);
      map->removePoint(points, ball->getHitPointPositionX(), ball->getHitPointPositionY());
    } else {
      ball->move(map->getMapFields(), X, Y, isGameOver);
    }
    
    if(ball->getMoveException()){
      ball->move(map->getMapFields(), X, Y, isGameOver);
    }

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
      isExit = true;
    }
  } while(!isExit && !isGameOver);

  if(isGameOver) {
    map->displayGameOver();
  }

  kb->stopThread();
  clear();
};