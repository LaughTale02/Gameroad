#pragma once
#ifndef cDinausor_H_
#define cDinausor_H_

#include "cAnimal.h"

class cDinausor :public cAnimal 
{
private:
	vector<string>dinausor;
	int mX, mY;
	int newX = 0;
public:
	cDinausor();
	void setInfo(int, int);

	void Move1Step(int);
	void out();
	void clean(int, int);

	int getX();
	int getXW();
	int getY();
	int getYH();

	void tell();

	~cDinausor();
};
#endif // !cDinausor_H_


