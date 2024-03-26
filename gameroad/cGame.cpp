#include "cGame.h"

cGame::cGame() 
{
	axt = new cTruck[Level];
	axh = new cCar[Level];
	ac = new cBird[Level];
	akl = new cDinausor[Level];
	for (int i = 0; i < Level; ++i) {
		axt[i].setInfo(leftSize+ 30 * i , hTruck);
		axh[i].setInfo(leftSize + 30 * i, hCar);
		ac[i].setInfo(leftSize + 30 * i, hBird);
		akl[i].setInfo(leftSize + 30, hDinausor);
	}
}

cGame::~cGame() 
{
	delete[] axt;
	delete[] axh;
}

void cGame::drawGame()
{
    GotoXY(125, 12);
	cout << Level;
	GotoXY(125, 14);
	cout << speed;
}

void cGame::updatePosPeople(char c) 
{
	cn.out();
	if (c == 'w' || c == 'W')
		cn.Up(speed);
	if (c == 'a' || c == 'A')
		cn.Left(speed);
	if (c == 's' || c == 'S')
		cn.Down(speed);
	if (c == 'd' || c == 'D')
		cn.Right(speed);
}

void cGame::updatePosVehicle() 
{
	for (int i = 0; i < Level; ++i) 
	{
		axt[i].Move1Step(speed);
		axh[i].Move1Step(speed);
	}
}

void cGame::updatePosAnimal() 
{
	for (int i = 0; i < Level; ++i) 
	{
		ac[i].Move1Step(speed);
		akl[i].Move1Step(speed);
	}
}

bool cGame::check() 
{
	return !(cn.isImpact(axh,axt,speed));
}

bool cGame::levelUp() 
{
	if (cn.isFinish()) 
	{
		++Level;
		startGame(); 
		return true;
	}
	return false;
}

void cGame::startGame() 
{
	delete[] axh;
	delete[] axt;
	delete[] ac;
	delete[] akl;
	cn.reset();
	cleanRectangle(l+1, r, t+1, b);
	axt = new cTruck[Level];
	axh = new cCar[Level];
	ac = new cBird[Level];
	akl = new cDinausor[Level];
	for (int i = 0; i < Level; ++i) {
		axt[i].setInfo(i*15 + 15, hTruck);
		axh[i].setInfo(i*20 +15, hCar);
		ac[i].setInfo(i*20 +15, hBird);
		akl[i].setInfo(i * 20 + 15, hDinausor);
	}
}

void cGame::resetGame() 
{
	Level = 1;
	startGame();
}

void cGame::exitGame(thread* b) 
{
	//TerminateThread(b, 0);
	//exit(1); //khong toi uu
	//join();
	//b.join();
	system("cls");
	b->join();
}

void cGame::pauseGame(HANDLE b) 
{
	SuspendThread(b);
}

void cGame::resumeGame(HANDLE b) 
{
	ResumeThread(b);
}

bool cGame::loadGame(string filename) 
{
	filename += ".txt";
	fstream fin;
	fin.open(filename, ios::in);
	if (!fin.is_open()) {
		GotoXY(115, 36, "No account.");
		return false;
	}
	else {
		fin >> Level >> speed;
		fin.close();
		startGame();
	}
	return true;
}

void cGame::saveGame(string filename) 
{
	filename += ".txt";
	fstream fout;
	fout.open(filename, ios::out);
	fout << Level << endl;
	fout << speed;
	fout.close();
}

int cGame::getLevel() 
{
	return Level;
}

cPeople cGame::getPeople() 
{
	return cn;
}

cCar* cGame::getCar() 
{
	return axh;
}
cTruck* cGame::getTruck() 
{
	return axt;
}

cBird* cGame::getBird() 
{
	return ac;
}

cDinausor* cGame::getDinausor() 
{
	return akl;
}

void cGame::setSpeed(int ispeed) 
{
	speed = ispeed;
}












