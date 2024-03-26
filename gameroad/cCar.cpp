#include "cCar.h"

cCar::cCar() 
{
	mX = mY = 0;
}

void cCar::setInfo(int startCol, int startRow) 
{
	mX = startCol % rightSize;
	mY = startRow;
	car.push_back(" __/_|  \\___,");
	car.push_back("|  _    _   |");
	car.push_back("'-(_)--(_)--'");
	newX = mX;
}

void cCar::Move1Step(int speed) 
{
	clean(mX, mY);
	if (newX <= leftSize)
		newX = rightSize - 15;
	mX = newX;
	out();
	newX -= speed;
}

void cCar::out() 
{
	for (int i = 0; i < car.size(); i++) 
	{
		GotoXY(mX, mY + i);
		cout << car[i];
	}
}

void cCar::clean(int x, int y) 
{
	for (int i = 0; i < car.size(); ++i){
		GotoXY(x, y + i);
		for(int j=0;j<car[i].length();j++)
			cout << " ";
	} 
}

int cCar::getX()
{
	return mX ;
}

int cCar::getXW() 
{
	return mX + car[mX-getX()].length();
}

int cCar::getY() 
{
	return mY;
}

int cCar::getYH() 
{
	return mY + (int)car.size() - 1;
}

cCar::~cCar() 
{
	car.clear();
}
