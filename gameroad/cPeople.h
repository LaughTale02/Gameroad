#pragma once
#ifndef cPeople_H_
#define cPeople_H_

#include <iostream>
using namespace std;

#include "cConsole.h"
#include "cTruck.h"
#include "cCar.h"
#include "cBird.h"
#include "cDinausor.h"

static bool mState;

class cPeople 
{
private:
	int mX, mY;
	vector<string> people;
public:
	cPeople();

	void out();
	void clean();
	
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	
	bool forImpact(int,int,int,int);
	bool isImpact(cCar*,cTruck*,int);
	bool isImpact(cBird*,cDinausor*,int);
	bool isDead();
	bool isFinish();

	void reset();

	void deadFilter();

	~cPeople();
};
#endif // !cPeople_H_

