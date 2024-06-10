#include "Header.h"

newSETTINGS_ALL settings;
CHORDS chord = getConsleChords();
HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);

int activeColor;
int lastColor;

void myApp()
{
	cout << "text";
	while (1)
	{
		system("cls");
		newSettings();

		
		const int interface1Size = 4;
		int maxSize = 0;
		int cursoreLine = 0;
		int lastCursore = 0;
		int tapp;

		SetConsoleTextAttribute(hC, lastColor);
		ShowConsoleCursor(0);

		string settingsInterface1[interface1Size] = { "1. Войти","2. Зарегестрироваться","3. Информаия", "4. Выход"};

		for (int i = 0; i < interface1Size; i++) maxSize = max(settingsInterface1[i].size(), maxSize);

		for (int i = 0; i < interface1Size; i++) {
			setCursorPosition(chord.x  - settingsInterface1[i].size() /2 -22, 3 + chord.y / 4 + i * 3+8);
			cout << settingsInterface1[i];
		}

		while (1)
		{

			setCursorPosition(chord.x - settingsInterface1[lastCursore].size() / 2 - 25, 3 + chord.y / 4 + lastCursore * 3 + 8);
			SetConsoleTextAttribute(hC, lastColor);
			cout << "   " << settingsInterface1[lastCursore];

			setCursorPosition(chord.x - settingsInterface1[cursoreLine].size() / 2 - 25, 3 + chord.y / 4 + cursoreLine * 3 + 8);
			SetConsoleTextAttribute(hC, activeColor);
			cout << ">> " << settingsInterface1[cursoreLine];


			setCursorPosition(chord.x / 4 + (maxSize + 3) , 3 + chord.y / 4 + cursoreLine * 3);
			tapp = _getch();

			if (tapp == 80 || tapp == 72)
			{
				lastCursore = cursoreLine;
				cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
			}
			else if (tapp == 27 || tapp == 52 || (cursoreLine == interface1Size - 1 && tapp == 13))
			{
				leave();
			}
			else if (tapp == 13 )
			{
				if (cursoreLine == 0) { entrance(); }
				if (cursoreLine == 1) { reg(); }
				if (cursoreLine == 2) { inf(); }
			}
			
		}
	}
}

void inf()
{

}
void reg()
{

}
void entrance()
{

}

void newSettings()
{
	settings = readSettingsFile();

	if (settings.theme == "LIGHT")
	{
		system("color 70");
		activeColor = 112;
		lastColor = 120;
	}
	else if (settings.theme == "BLUE") system("color 1F");
	else system("color 0e");

	nameController(settings.name);
}