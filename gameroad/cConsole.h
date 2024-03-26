#pragma once
#ifndef cConsole_H_
#define cConsole_H_

#include <iostream>
using namespace std;

#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

static int num = 3;

static int leftSize = 5;
static int rightSize = 110;
static int topSize = 12;
static int botSize = 40;

static int hTruck = 28;
static int hCar = 34;
static int hBird = 22;
static int hDinausor = 16;

const int r = 110;
const int l = 4;
const int t = 11;
const int b = 40;

//static bool music = true;

void GotoXY(int x, int y);

void GotoXY(int x, int y, string);

void FixConsoleWindow();

void resizeConsole(int width, int height);

void hideCursor();

void textcolor(int);

void SetColor(int backgound_color, int text_color);

//for class

//void peopleDeadConsole();

//for main
void drawRectangle(int, int, int, int);

void cleanRectangle(int, int, int, int);

//for introduction
void introCar(int, int);

void loading();

void welcome();

void introConsole();

void menuIntroConsole();

void menuConsole();

void drawHeader();

void drawConsole();

void levelUpConsole();

void gameOverConsole();

void goodbyeConsole();
#endif // !cConsole_H_

