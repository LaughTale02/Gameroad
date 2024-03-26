#include <iostream>
#include <thread>
#include "cConsole.h"
#include "cGame.h"
#include "cVehicle.h"
#include "cCar.h"
#include "cTruck.h"
#include "cPeople.h"
#include "cAnimal.h"
#include <iostream>
using namespace std;

#include "cBird.h"
#include "cDinausor.h"

static bool IS_RUNNING = true;
static bool stop = false;
static int temp;
static char MOVING;
cGame cg;
static bool light = true;//green

void trafficLight() 
{
	if (light)
		textcolor(1);
	else
		textcolor(12);
	GotoXY(rightSize - 1, hTruck);
	cout << char(219);
	GotoXY(leftSize, hCar);
	cout << char(219);
	textcolor(15);
}

void changeLight() 
{
	while (1) {
		Sleep(1000);
		light = !light;
		if (stop)
			break;
	}
}

void subThread() 
{
	while (1) {
		if (IS_RUNNING) 
		{
            trafficLight();
			cg.drawGame();
			if (!cg.getPeople().isDead()) 
			{
				cg.updatePosPeople(MOVING);
			}
			MOVING = ' ';
			if (light)
				cg.updatePosVehicle();
			cg.updatePosAnimal();
			if (cg.getPeople().isImpact(cg.getCar(), cg.getTruck(), cg.getLevel()) ||
				cg.getPeople().isImpact(cg.getBird(), cg.getDinausor(), cg.getLevel())) 
			{
				IS_RUNNING = false;
				gameOverConsole();
				Sleep(1500);
				GotoXY(115, 35);
				cout << "Do u want play again? (Y/N)";// << cg.getPeople().getmState();
				//cg.check(); //importance for the code

			}
			Sleep(100 - cg.getLevel() * 20 + 1);
			if (cg.levelUp()) {
				light = true;
				levelUpConsole();
				cg.startGame();
			}
		}
		if (stop)
			break;
	}
}


int main() 
{
	FixConsoleWindow();
	resizeConsole(1080, 720);
	hideCursor();
	introConsole();
	int choice;
	string name;
	menuIntroConsole();
	cin >> choice;
	cin.ignore();

	if (choice == 2) 
	{
		GotoXY(60, 26, "Enter name file: ");
		getline(cin, name);
		cg.loadGame(name);
	}
	else if (choice == 3) {
		int c;
		GotoXY(60, 26, "Music: 1.On 2.Off: ");
		cin >> c;
		//if (c != 1)
			//music = 0;
			GotoXY(60, 27, "Select speed: ");
		cin >> c;
		cg.setSpeed(c);
		cin.ignore();
	}
	else if (choice == 4)
		return 0;
	cleanRectangle(50, 90, 10, 30);
	drawConsole();

	int temp;
	IS_RUNNING = true;
	thread t2(changeLight);
	thread t1(subThread);
	while (1) {

		temp = toupper(_getch());

		if (temp == 'l' || temp == 'L') 
		{
			cg.pauseGame(t1.native_handle());
			GotoXY(115, 35, "Enter name file: ");
			getline(cin, name);
			cleanRectangle(112, 143, 32, 40);
			cg.saveGame(name);
			cg.resumeGame(t1.native_handle());
		}
		if (temp == 't' || temp == 'T') 
		{
			cg.pauseGame(t1.native_handle());
			GotoXY(115, 35, "Enter name file: ");
			getline(cin, name);
			cg.loadGame(name);
			cleanRectangle(112, 143, 32, 40);
			cg.resumeGame(t1.native_handle());
		}
		if (temp == 'x' || temp == 'X') 
		{
			cg.resetGame();
			IS_RUNNING = true;
			light = true;
		}
        if (!cg.getPeople().isDead()) {//!stop) {
			if (temp == 27) {
				IS_RUNNING = false;
				stop = true;
				cg.exitGame(&t1);
				t2.join();
				goodbyeConsole();
				return 0;
			}
			else if (temp == 'p' || temp == 'P')
				cg.pauseGame(t1.native_handle());
			else if (temp == 'r' || temp == 'R') {
				cg.resumeGame(t1.native_handle());
			}
			MOVING = temp;
		}
		else 
		{
			cg.pauseGame(t1.native_handle());
			if (temp == 'y' || temp == 'Y') 
			{
				IS_RUNNING = true;
				light = true;
				cg.startGame();
				cleanRectangle(112, 143, 32, 40);
				cg.resumeGame(t1.native_handle());
			}
			else 
			{
				cg.resumeGame(t1.native_handle());
				IS_RUNNING = false;
				stop = true;
				cg.exitGame(&t1);
				t2.join();
				goodbyeConsole();
				return 0;
			}
		}
	}
	t1.join();
	t2.join();
	return 0;
}

