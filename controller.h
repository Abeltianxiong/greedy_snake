#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <conio.h>

#include "tools.h"
#include "startinterface.h"
#include "map.h"

#include "snake.h"





//#include <windows.h>
#include <time.h>
//#include "food.h"

class Controller
{
public:
	Controller() { speed = 200; key = 1; score = 0; }
	void Game();
	void Start();
	void Select();
	void DrawGame();
	int PlayGame();
private:
	int speed;
	int key;
	int score;

};




#endif // !CONTROLLER_H
