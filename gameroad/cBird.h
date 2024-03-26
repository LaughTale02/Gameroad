#pragma once
#ifndef cBird_H_
#define cBird_H_

#include "cAnimal.h"

class cBird :public cAnimal 
{
private:
	vector<string>bird;
	int mX, mY;
	int newX = 0;
public:
	cBird();
	
	void setInfo(int, int);

	void Move1Step(int);
	void out();
	void clean(int, int);

	int getX();
	int getXW();
	int getY();
	int getYH();

	void tell();

	~cBird();
};
#endif // !cBird_H_


