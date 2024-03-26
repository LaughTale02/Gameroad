#include "cPeople.h"

cPeople::cPeople() 
{
	people.push_back(" o/");
	people.push_back("/S ");
	people.push_back("/ \\");
	mX = (leftSize + rightSize) / 2;
	mY = botSize - 3;
	mState = true;
};

void cPeople::out() 
{
	for (int i = 0; i < people.size(); i++) 
	{
		GotoXY(mX, mY + i);
		cout << people[i];
	}
}

void cPeople::clean() 
{
	for (int i = 0; i < people.size(); i++) 
	{
		GotoXY(mX, mY + i);
		for (int j = 0; j < people[i].length(); j++)
			cout << " ";
	}
}

void cPeople::Up(int speed) 
{
	clean();
	mY = max(mY - speed , topSize);
	out();
}

void cPeople::Left(int speed) 
{
	clean();
	mX = max(mX - speed, leftSize);
	out();
}

void cPeople::Right(int speed ) 
{
	clean();
	mX = min(mX + speed, rightSize - 3);
	out();
}

void cPeople::Down(int speed) 
{
	clean();
	mY = min(mY + speed, botSize - 3);
	out();
}

bool cPeople::forImpact(int val1, int val2, int val3, int val4) 
{
	int count = 0;
	if (mX > val2 || mX + people[0].length() < val1)
		++count;
	if (mY > val4 || mY + people.size() - 1 < val3)
		++count;
	if (count == 0) 
	{
		mState = false;
		return true;
	}
	return false;
}

bool cPeople::isImpact(cCar *b,cTruck* c,int numVehicle) 
{
	for (int i = 0; i < numVehicle; ++i)
		if (forImpact(b[i].getX(), b[i].getXW(), b[i].getY(), b[i].getYH())
			|| forImpact(c[i].getX(), c[i].getXW()  , c[i].getY(), c[i].getYH())) {
			mState = false;
			deadFilter();
			return true;
		}
	return false;
}

bool cPeople::isImpact(cBird* b, cDinausor* c, int numAnimal) 
{
	for (int i = 0; i < numAnimal; ++i) {
		if (forImpact(b[i].getX(), b[i].getXW(), b[i].getY(), b[i].getYH())) {
			b->tell();
			mState = false;
			deadFilter();
			return true;
		}
		if (forImpact(c[i].getX(), c[i].getXW(), c[i].getY(), c[i].getYH())) {
			c->tell();
			mState = false;
			deadFilter();
			return true;
		}
	}
	return false;
}

bool cPeople::isDead() 
{
	return !mState;// == false;
}

bool cPeople::isFinish() 
{
	if (mY <= topSize ) {
		Sleep(50);
		clean();
		return true;
	}
	return false;
}

void cPeople::reset() 
{
	clean();
	mX = (leftSize + rightSize) / 2;
	mY = botSize - 3;
	mState = true;
}

void cPeople::deadFilter() 
{
	cleanRectangle(mX, mX + 3, mY, mY + 3);
	SetColor(12, 15);
	GotoXY(mX, mY,   "\\O/");
	GotoXY(mX, mY+1, " M ");
	GotoXY(mX, mY+2, "/ \\");
	Sleep(900);
	SetColor(4, 15);
	GotoXY(mX, mY + 1, " X ");
	Sleep(600);
	GotoXY(mX, mY, "\\ /");
	GotoXY(mX, mY + 2, "/ \\");
	Sleep(600); 
	SetColor(0, 15);
}

cPeople::~cPeople()
{
}
