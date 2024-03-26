#pragma once
#ifndef cAnimal_H_
#define cAnimal_H_

#include "cConsole.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma comment (lib, "winmm.lib")

static bool music = true;

class cAnimal //pure class
{
private:
	int mX, mY;
public:
	cAnimal();
	virtual void Move1Step();
	virtual void out();
	virtual void clean(int, int);
	virtual int getX() = 0;
	virtual int getXW() = 0;
	virtual int getY() = 0;
	virtual int getYH() = 0;
	virtual void Move1Step(int, int) {}
	virtual void setInfo(int, int) = 0 {}
};
#endif // !cAnimal_H_

