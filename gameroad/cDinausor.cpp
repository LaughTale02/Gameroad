#include "cDinausor.h"

cDinausor::cDinausor() 
{
	mX = mY = 0;
}

void cDinausor::setInfo(int startCol, int startRow) 
{
	mX = startCol % rightSize;
	mY = startRow;
	dinausor.push_back(" __               ");
	dinausor.push_back("(_ \\              ");
	dinausor.push_back("  \\ \\_/\\/\\/\\_     ");
	dinausor.push_back("   \\         |_   ");
	dinausor.push_back("    |  ) |  )  |_ ");
	dinausor.push_back("    |_|--|_|'-.__\\");
	newX = mX;
}

void cDinausor::Move1Step(int speed) 
{
	clean(mX, mY);
	if (newX <= leftSize)
		newX = rightSize - 18;
	mX = newX;
	out();
	newX -= speed;
}

void cDinausor::out() 
{
	for (int i = 0; i < dinausor.size(); i++) 
	{
		GotoXY(mX, mY + i);
		cout << dinausor[i];
		//cout << mX << " ";
	}
}

void cDinausor::clean(int x, int y) 
{
	for (int i = 0; i < dinausor.size(); ++i) {
		GotoXY(x, y + i);
		for (int j = 0; j < dinausor[i].length(); j++)
			cout << " ";
	}
}

int cDinausor::getX() 
{
	return mX;
}

int cDinausor::getXW() 
{
	return mX + (int)dinausor[mX - getX()].length();
}

int cDinausor::getY() 
{
	return mY;
}

int cDinausor::getYH() 
{
	return mY + (int)dinausor.size() - 1;
}

void cDinausor::tell() {
	if(music)
		PlaySound(TEXT("dinausor.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
}

cDinausor::~cDinausor() 
{
	dinausor.clear();
}
