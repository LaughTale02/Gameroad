#include "cTruck.h"

cTruck::cTruck() 
{
	mX = mY = 0;
}

void cTruck::setInfo(int startCol, int startRow) 
{
	mX = startCol + leftSize;
	//mX = 10;
	mY = startRow;
	truck.push_back("/====\\");
	truck.push_back("|xxx| |");
	truck.push_back("-O---O'");
	newX = mX;
}

void cTruck::Move1Step(int speed) 
{
	clean(mX, mY);
	if (newX >= rightSize -7)
		newX = leftSize +1;
	mX = newX;
	out();
	newX += speed;
}

void cTruck::out() 
{
	for (int i = 0; i < truck.size(); ++i) 
	{
		GotoXY(mX,mY+i);
		cout << truck[i] ;
	}
}

void cTruck::clean(int x, int y) 
{
	for (int i = 0; i < truck.size(); ++i) 
	{
		GotoXY(x, y + i);
		for(int j=0;j<truck[i].size();++j)
			cout << " ";                                                     
	}
}

int cTruck::getX() 
{
	return mX;
}

int cTruck::getXW() 
{
	return (int)(mX+truck[0].length());
}

int cTruck::getY() 
{
	return mY;
}

int cTruck::getYH() 
{
	return (int)(mY + truck.size() - 1);
}

cTruck::~cTruck() 
{
	truck.clear();
}