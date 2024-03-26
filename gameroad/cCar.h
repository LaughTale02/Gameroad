#pragma once
#ifndef cCar_H_
#define cCar_H_

#include "cVehicle.h"

class cCar:public cVehicle
{
private:
	vector<string>car;
	int mX, mY;
	int newX = 0;
public:
	cCar();
	void setInfo(int, int);

	void Move1Step(int);
	void out();
	void clean(int, int);

	int getX();
	int getXW();
	int getY();
	int getYH();

	~cCar();
};
#endif // !cCar_H_


