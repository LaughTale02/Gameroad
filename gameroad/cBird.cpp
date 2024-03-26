#include "cBird.h"

cBird::cBird() 
{
	mX = 0;
	mY = 0;
}

void cBird::setInfo(int startCol, int startRow) 
{
	mX = startCol % rightSize;
	mY = startRow;
	bird.push_back("  _,");
	bird.push_back("_(_p>");
	bird.push_back("\\<_)");
	bird.push_back(" ^^ ");
	newX = mX;
}

void cBird::Move1Step(int speed) 
{
	clean(mX, mY);
	if (newX >= rightSize - 7)
		newX = leftSize + 1;
	mX = newX;
	out();
	newX += speed;
}

void cBird::out() {
	for (int i = 0; i < bird.size(); i++) 
	{
		GotoXY(mX, mY + i);
		cout << bird[i];
	}
}

void cBird::clean(int x, int y) 
{
	for (int i = 0; i < bird.size(); ++i) 
	{
		GotoXY(x, y + i);
		for (int j = 0; j < bird[i].length(); j++)
			cout << " ";
	}
}

int cBird::getX() 
{
	return mX;
}

int cBird::getXW() 
{
	return mX + bird[mX - getX()].length();
}

int cBird::getY() 
{
	return mY;
}

int cBird::getYH() 
{
	return mY + (int)bird.size() - 1;
}

void cBird::tell() 
{
	if(music)
		PlaySound(TEXT("bird.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
}

cBird::~cBird() 
{
	bird.clear();
}
