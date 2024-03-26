#pragma once
#ifndef cTruck_H_
#define cTruck_H_

#include "cVehicle.h"

class cTruck :public cVehicle 
{
private:
	vector<string> truck;
	int mX, mY; 
	int newX = leftSize;
public:
	cTruck();
	void setInfo(int, int);

	void Move1Step(int);
	void out();
	void clean(int, int);

	int getX();
	int getXW();
	int getY();
	int getYH();

	~cTruck();
};
#endif // !cTruck_H_


