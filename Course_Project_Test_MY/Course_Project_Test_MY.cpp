#include "Header.h"

Function text;



int main()
{
	allLang();
	//_getch();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	/*for (int k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " I want to be nice today!" << endl;
	}*/
	//system("color 8a");
	_getch();
	system("cls");
	//SetConsoleCursorPosition();
	writeBorder();

}

