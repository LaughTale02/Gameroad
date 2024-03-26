#pragma once
#ifndef cVehicle_H_
#define cVehicle_H_

#include "cConsole.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cVehicle //pure class
{
private:
	int mX, mY;
public:
	cVehicle();
	virtual void Move1Step();
	virtual void out();
	virtual void clean(int ,int);
	virtual int getX() = 0;
	virtual int getXW() = 0;
	virtual int getY() = 0;
	virtual int getYH() = 0;
	virtual void Move1Step(int, int) {}
	virtual void setInfo(int, int) =0 {}
	~cVehicle();
};
#endif // !cVehicle_H_

