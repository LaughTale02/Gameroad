#pragma once
#ifndef cGame_H_
#define cGame_H_

#include "cConsole.h"
#include "cVehicle.h"
#include "cCar.h"
#include "cTruck.h"
#include "cPeople.h"
#include "cAnimal.h"
#include "cBird.h"
#include "cDinausor.h"
#include <thread>
#include <string>
#include <fstream>

#define maxAnimal 5
#define maxVehicle 5
#define maxLevel 5
#define maxSpeed 5

class cGame  
{
private:
	cTruck *axt;
	cCar* axh;// [3] ; = NULL;
	cBird* ac;
	cDinausor* akl;
	cPeople cn;

	int Level = 1;
	int speed = 1;
public:
	cGame();
	
    void drawGame();
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();

	bool check();
	bool levelUp();

	void startGame();
	void resetGame();
	void exitGame(thread*);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	bool loadGame(string);
	void saveGame(string);

	int getLevel();
	cPeople getPeople();
	cCar* getCar();
	cTruck* getTruck();
	cBird* getBird();
	cDinausor* getDinausor();
	void setSpeed(int);

	~cGame();
};
#endif // cGame_H_
