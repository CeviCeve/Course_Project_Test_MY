#include "Header.h"

CHORDS chords = getConsleChords();
string master = "МАСТЕР НАСТРОЕК";
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void masterOfSettings()
{
	system("cls");
		
	chords = getConsleChords();

	setCursorPosition(chords.x/2-master.size()/2, 1);
	cout << master;
	SetConsoleTextAttribute(hConsole, 6);

	settingMenu_1();
		//cout << chords.x << " " << chords.y;
	
}

void settingMenu_1()
{
	const int interface1Size = 5;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;

	string settingsInterface1[interface1Size] = { "Название компании:","Электронная почта:","Пароль компании:","Повтор пароля:","Далее ->" };
	string newSettings[interface1Size] = { "","","","" };

	for (int i = 0; i < interface1Size; i++) maxSize = max(settingsInterface1[i].size(), maxSize);

	for (int i = 0; i < interface1Size; i++) {
			setCursorPosition(chords.x / 4, 3 + chords.y/4 + i * 3); 
			cout << settingsInterface1[i];
		}

	while (1)
	{	
		setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 + lastCursore * 3);
		SetConsoleTextAttribute(hConsole, 6);
		cout << "   " << settingsInterface1[lastCursore];

		setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 + cursoreLine * 3);
		SetConsoleTextAttribute(hConsole, 14);
		cout << ">> " << settingsInterface1[cursoreLine];

		setCursorPosition(chords.x / 4 +(maxSize + 3)+ newSettings[cursoreLine].length(), 3 + chords.y / 4 + cursoreLine * 3);
		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if ((tapp >= 65 && tapp <= 122 && cursoreLine != 4) || (tapp >=48 && tapp<=57))
		{
			newSettings[cursoreLine] = newSettings[cursoreLine] + static_cast<char>(tapp);
			cout << static_cast<char>(tapp);
		}
		else if (tapp == 8 && newSettings[cursoreLine] != "")
		{
			newSettings[cursoreLine].pop_back();
			setCursorPosition(chords.x / 4 + (maxSize + 3) + newSettings[cursoreLine].length(), 3 + chords.y / 4 + cursoreLine * 2);
			cout << " ";
		}
		else if (tapp == 41)
		{
			setCursorPosition(1, 1);
			cout << newSettings[cursoreLine] << endl;
		}
		//cout<< tapp<< " ";
	}
}