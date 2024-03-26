#include "cConsole.h"

void GotoXY(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y, string s) 
{
	GotoXY(x, y);
	cout << s;
}

void FixConsoleWindow() 
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void textcolor(int x) 
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int backgound_color, int text_color)
{
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(console, color_code);
}


//void peopleDeadConsole() {
//	int i = 10, j = 20;
//	GotoXY(i, j++, "_____.___.                  .___.__      ");
//	GotoXY(i, j++, "\\__  |   | ____  __ __    __| _/|__| ____  ");
//	GotoXY(i, j++, " /   |   |/  _ \\|  |  \\  / __ | |  |/ __ \\ ");
//	GotoXY(i, j++, " \\____   (  <_> )  |  / / /_/ | |  \\  ___/ ");
//	GotoXY(i, j++, " / ______|\\____/|____/  \\____ | |__|\___  >");
//	GotoXY(i, j++, " \\/                          \\/         \\/ ");
//}

void drawRectangle(int L, int R, int T, int B) 
{

	for (int i = L; i < R; ++i) {
		GotoXY(i, T);
		cout << char(196);
		GotoXY(i, B);
		cout << char(196);
	}
	for (int i = T; i < B; ++i) {
		GotoXY(L, i);
		cout << char(179);
		GotoXY(R, i);
		cout << char(179);
	}
	GotoXY(L, T);
	cout << char(218);
	GotoXY(L, B);
	cout << char(192);
	GotoXY(R, T);
	cout << char(191);
	GotoXY(R, B);
	cout << char(217);

}

void cleanRectangle(int L, int R, int T, int B) 
{
	string s = "";
	for (int i = L; i < R; ++i)
		s += " ";
	for (int i = T; i < B; ++i)
		GotoXY(L, i, s);
	//cout << "c";
}

void introCar(int i, int j) 
{
	GotoXY(i, j, "                      ________________________");
	GotoXY(i, ++j, "                   /  |           |          \\ ");
	GotoXY(i, ++j, "                  /   |           |           \\ ");
	GotoXY(i, ++j, "      ___________/____|___________|__________()\\___________________?");
	GotoXY(i, ++j, "    /__________________|_=_________|_=___________|_________________| ");
	GotoXY(i, ++j, "    [           ______ |           | .           | ==  ______      | ");
	GotoXY(i, ++j, "  __[__        /00  00\\|           |             |    /$$  00\    _>>> ");
	GotoXY(i, ++j, " {_____)______|00    00|___________|_____________|___|00    00|__/// ");
	GotoXY(i, ++j, "  ______________00__00_________________________________00__00________ ");
}

void loading()
{
	GotoXY(73, 27);
	cout << "LOADING : ";
	for (int i = 0; i < 100; i++)
	{
		GotoXY(84, 27);
		cout << i << "%";
		Sleep(10);
		GotoXY(35 + i, 28);
		cout << char(219);
	}
}

void welcome() 
{
	int i = 20, j = 10;
	GotoXY(i, ++j, " /$$      /$$           /$$                                                      /$$       /$$   ");
	GotoXY(i, ++j, "| $$  /$ | $$          | $$                                                    /$$$$$$   /$$$$$$ ");
	GotoXY(i, ++j, "| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$        /$$__  $$ /$$__  $$");
	GotoXY(i, ++j, "| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$      | $$  \__/| $$  \__/");
	GotoXY(i, ++j, "| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \\ $$| $$ \\ $$ \\ $$| $$$$$$$$      |  $$$$$$ |  $$$$$$ ");
	GotoXY(i, ++j, "| $$$/ \\  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/       \\____  $$ \\____  $$");
	GotoXY(i, ++j, "| $$$/ \\  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/       \\____  $$ \\____  $$");
	GotoXY(i, ++j, "| $$/   \\  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$       /$$  \\ $$ /$$  \\ $$");
	GotoXY(i, ++j, "|__/     \\__/ \\_______/|__/ \\_______/ \\______/ |__/ |__/ |__/ \\_______/      |  $$$$$$/|  $$$$$$/");
	GotoXY(i, ++j, "                                                                              \\_  $$_/  \\_  $$_/ ");
	GotoXY(i, ++j, "                                                                                \\__/      \\__/   ");
}

void title() 
{
	int i = 15, j = 10;
	textcolor(10);
	GotoXY(i, ++j, " ________   ________   ________   ________");
	GotoXY(i, ++j, "|\\   __  \\ |\\   __  \\ |\\   __  \\ |\\   ___ \\  ");
	GotoXY(i, ++j, "\\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\_|\\ \\  ");
	GotoXY(i, ++j, " \\ \\   _  _\\\\ \\  \\\\\\  \\\\ \\   __  \\\\ \\  \\ \\\\ \\  ");
	GotoXY(i, ++j, "  \\ \\  \\\\  \\|\\ \\  \\\\\\  \\\\ \\  \\ \\  \\\\ \\  \\_\\\\ \\  ");
	GotoXY(i, ++j, "   \\ \\__\\\\ _\\ \\ \\_______\\\\ \\__\\ \\__\\\\ \\_______\\   ");
	GotoXY(i, ++j, "    \\|__|\\|__| \\|_______| \\|__|\\|__| \\|_______|");
	j += 2;
	GotoXY(i, ++j, " ________   ________   ________   ________    ________   ___    ________   ________");
	GotoXY(i, ++j, "|\\   ____\\ |\\   __  \\ |\\   __  \\ |\\   ____\\  |\\   ____\\ |\\  \\ |\\   ___  \\ |\\   ____\\ ");
	GotoXY(i, ++j, "\\ \\  \\___| \\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\___|_ \\ \\  \\___|_\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\___|");
	GotoXY(i, ++j, " \\ \\  \\     \\ \\   _  _\\\\ \\  \\\\\\  \\\\ \\_____  \\ \\ \\_____  \\\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\  ___ ");
	GotoXY(i, ++j, "  \\ \\  \\____ \\ \\  \\\\  \\|\\ \\  \\\\\\  \\\\|____|\\  \\ \\|____|\\  \\\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\|\\  \\ ");
	GotoXY(i, ++j, "   \\ \\_______\\\\ \\__\\\\ _\\ \\ \\_______\\ ____\\_\\  \\  ____\\_\\  \\\\ \\__\\\\ \\__\\\\ \\__\\\\ \\_______\\  ");
	GotoXY(i, ++j, "    \\|_______| \\|__|\\|__| \\|_______||\\_________\\|\\_________\\\\|__| \\|__| \\|__| \\|_______| ");
	GotoXY(i, ++j, "                                    \\|_________|\\|_________|");
	j += 2;
	GotoXY(i, ++j, " ________   ________   _____ ______    _______");
	GotoXY(i, ++j, "|\\   ____\\ |\\   __  \\ |\\   _ \\  _   \\ |\\  ___ \\ ");
	GotoXY(i, ++j, "\\ \\  \\___| \\ \\  \\|\\  \\\\ \\  \\\\\\__\\ \\  \\\\ \\   __/|");
	GotoXY(i, ++j, " \\ \\  \\  ___\\ \\   __  \\\\ \\  \\\\|__| \\  \\\\ \\  \\_|/__ ");
	GotoXY(i, ++j, "  \\ \\  \\|\\  \\\\ \\  \\ \\  \\\\ \\  \\    \\ \\  \\\\ \\  \\_|\\ \\ ");
	GotoXY(i, ++j, "   \\ \\_______\\\\ \\__\\ \\__\\\\ \\__\\    \\ \\__\\\\ \\_______\\ ");
	GotoXY(i, ++j, "    \\|_______| \\|__|\\|__| \\|__|     \\|__| \\|_______|");
}

void introConsole() 
{
	for (int i = 2; i < 40; ++i) {
		introCar(i, 10);
		Sleep(15);
	}
	loading();

	system("cls");
	welcome();
	
	Sleep(1000);
	system("cls");
	title();
	Sleep(1000);
	system("cls");
}

void menuIntroConsole() 
{
	drawRectangle(58, 80, 15, 24);
	GotoXY(60, 16, "1. New Game");
	GotoXY(60, 18, "2. Load Game");
	GotoXY(60, 20, "3. Settings");
	GotoXY(60, 22, "4. Exit");
	GotoXY(60, 26, "Your choice: ");
}

void menuConsole() 
{
	drawRectangle(112, 143, 11, 15);
	GotoXY(115, 12);
	cout << "Level: ";
	GotoXY(115, 14);
	cout << "Speed: ";

    drawRectangle(112, 143, 16, 30);
	GotoXY(115, 17);
	cout << "L - Save Game";
	GotoXY(115, 19);
	cout << "T - Load Game";
	GotoXY(115, 21);
	cout << "X - New Game";
	GotoXY(115, 23);
	cout << "P - Pause Game";
	GotoXY(115, 25);
	cout << "R - Resume Game";
	GotoXY(115, 27);
	cout << "Esc - Exit Game";
}

void drawHeader() 
{
	int i = 14;
	GotoXY(i, 1);
	cout << "_________                            .__                                          .___                               ";
	GotoXY(i, 2);
	cout << "\\_   ___ \\_______  ____  ______ _____|__| ____    ____   _______  _________     __| _/    _________    _____   ____  ";
	GotoXY(i, 3);
	cout << "/    \\  \\/\\_  __ \\/  _ \\/  ___//  ___/  |/    \\  / ___\\  \\_  __ \\/  _ \\__  \\   / __ |    / ___\\__  \\  /     \\_/ __ \\ ";
	GotoXY(i, 4);
	cout << "\\     \\____|  | \\(  <_> )___ \\ \\___ \\|  |   |  \\/ /_/  >  |  | \\(  <_> ) __ \\_/ /_/ |   / /_/  > __ \\|  Y Y  \\  ___/ ";
	GotoXY(i, 5);
	cout << " \\______  /|__|   \\____/____  >____  >__|___|  /\\___  /   |__|   \\____(____  /\\____ |   \\___  (____  /__|_|  /\\___  > ";
	GotoXY(i, 6);
	cout << "        \\/                  \\/     \\/        \\//_____/                     \\/      \\/  /_____/     \\/      \\/     \\/ ";
}

void drawConsole() 
{
	drawHeader();
	drawRectangle(l, r, t, b);//khung tro choi
	menuConsole();
}

void levelUpConsole() 
{
	cleanRectangle(l + 1, r, t + 1, b);
	int i = 24, j = 20;
	textcolor(5);
	GotoXY(i, j++, " /$$                                     /$$       /$$   /$$          ");
	GotoXY(i, j++, "| $$                                    | $$      | $$  | $$          ");
	GotoXY(i, j++, "| $$        /$$$$$$  /$$    /$$ /$$$$$$ | $$      | $$  | $$  /$$$$$$ ");
	GotoXY(i, j++, "| $$       /$$__  $$|  $$  /$$//$$__  $$| $$      | $$  | $$ /$$__  $$");
	GotoXY(i, j++, "| $$      | $$$$$$$$ \\  $$/$$/| $$$$$$$$| $$      | $$  | $$| $$  \\ $$");
	GotoXY(i, j++, "| $$      | $$_____/  \\  $$$/ | $$_____/| $$      | $$  | $$| $$  | $$");
	GotoXY(i, j++, "| $$$$$$$$|  $$$$$$$   \\  $/  |  $$$$$$$| $$      |  $$$$$$/| $$$$$$$/");
	GotoXY(i, j++, "|________/ \\_______/    \\_/    \\_______/|__/       \\______/ | $$____/ ");
	GotoXY(i, j++, "                                                            | $$      ");
	GotoXY(i, j++, "                                                            | $$      ");
	GotoXY(i, j++, "                                                            |__/      ");
	Sleep(1000);
	cleanRectangle(l + 1, r, t + 1, b);
}

void gameOverConsole() 
{
	cleanRectangle(l + 1, r, t + 1, b);
	int i = 10, j = 20;
	GotoXY(i, j++, "  /$$$$$$                                           /$$$$$$                               ");
	GotoXY(i, j++, " /$$__  $$                                         /$$__  $$                              ");
	GotoXY(i, j++, "| $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$       | $$  \\ $$ /$$    /$$ /$$$$$$   /$$$$$$ ");
	GotoXY(i, j++, "| $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$      | $$  | $$|  $$  /$$//$$__  $$ /$$__  $$");
	GotoXY(i, j++, "| $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$      | $$  | $$ \\  $$/$$/| $$$$$$$$| $$  \\__/");
	GotoXY(i, j++, "| $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/      | $$  | $$  \\  $$$/ | $$_____/| $$      ");
	GotoXY(i, j++, "|  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$      |  $$$$$$/   \\  $/  |  $$$$$$$| $$       ");
	GotoXY(i, j++, " \\______/  \\_______/|__/ |__/ |__/ \\_______/       \\______/     \\_/    \\_______/|__/      ");
}

void goodbyeConsole() 
{
	int i = 30, j = 12;
	GotoXY(i, j, "  /$$$$$$                            /$$ /$$                            /$$ /$$ /$$");
	GotoXY(i, ++j, " /$$__  $$                          | $$| $$                          | $$| $$| $$");
	GotoXY(i, ++j, "| $$  \\__/  /$$$$$$   /$$$$$$   /$$$$$$$| $$$$$$$  /$$   /$$  /$$$$$$ | $$| $$| $$");
	GotoXY(i, ++j, "| $$ /$$$$ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$| $$  | $$ /$$__  $$| $$| $$| $$");
	GotoXY(i, ++j, "| $$|_  $$| $$  \\ $$| $$  \\ $$| $$  | $$| $$  \\ $$| $$  | $$| $$$$$$$$|__/|__/|__/");
	GotoXY(i, ++j, "| $$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$_____/            ");
	GotoXY(i, ++j, "|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$$|  $$$$$$$ /$$ /$$ /$$");
	GotoXY(i, ++j, " \\______/  \\______/  \\______/  \\_______/|_______/  \\____  $$ \\_______/|__/|__/|__/");
	GotoXY(i, ++j, "                                                   /$$  | $$                      ");
	GotoXY(i, ++j, "                                                  |  $$$$$$/                      ");
	GotoXY(i, ++j, "                                                   \\______/                       ");
	Sleep(900);
	GotoXY(1, 38);
}