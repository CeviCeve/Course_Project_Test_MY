#include "Header.h"

SETTINGS setting;
CHORDS chord = getConsleChords();
HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);

USER_SETTINGS userSetting[10000];
int sizeUserSettings = 0;

int activeColor;
int lastColor;

int userInSystem=-1;


void myApp()
{
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

		string settingsInterface1[interface1Size] = { "1. �����","2. ������������������","3. ����������", "4. �����"};

		for (int i = 0; i < interface1Size; i++) maxSize = max(settingsInterface1[i].size(), maxSize);

		

		while (1)
		{
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size; i++) {
				setCursorPosition(chord.x - settingsInterface1[i].size() / 2 - 22, 3 + chord.y / 4 + i * 3 + 8);
				cout << settingsInterface1[i];
			}

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
			else if(tapp == 49)entrance();
			else if (tapp == 50)reg();
			else if (tapp == 51)inf();

			
		}
	}
}

void inf()
{
	system("cls");
	newSettings();
	SetConsoleTextAttribute(hC, activeColor);

	const int interface1Size = 6;
	int maxSize = 0;
	string settingsInterface1[interface1Size] = { "��������","    ��������: ","    �����:    ","", "���������� �������� �� �� \"Job Easy\"", "\t�������� Pyt.Tech 2024-NOW" };

	for (int i = 0; i < interface1Size-2; i++) maxSize = max(settingsInterface1[i].size(), maxSize);
	for (int i = 0; i < interface1Size; i++) {
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface1[i];
		if (i == 1) cout << " " << setting.title;
		if (i == 2)cout << " " << setting.email;
		if(i==interface1Size-3 || i == interface1Size-2)	SetConsoleTextAttribute(hC, lastColor);
		else SetConsoleTextAttribute(hC, activeColor);
	}
	_getch();
	system("cls");
	newSettings();    
}

void reg()
{

}
void entrance()
{
	const int interface1Size = 4;
	int interface1Size2 = 0;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;

	string settingsInterface1[interface1Size] = { "�����:      ", "������:     ", "��� �������:", "�����"};
	string settingsInterface2[interface1Size] = { "", "", "", "�����" };
	string newSettings[interface1Size] = { "","","" };

	if (setting.login) { settingsInterface2[interface1Size2] = settingsInterface1[0]; interface1Size2++; }
	if (setting.password) { settingsInterface2[interface1Size2] = settingsInterface1[1]; interface1Size2++; }
	if (setting.codeIn) { settingsInterface2[interface1Size2] = settingsInterface1[2]; interface1Size2++; }
	settingsInterface2[interface1Size2] = settingsInterface1[3]; interface1Size2++;

	for (int i = 0; i < interface1Size2; i++)maxSize = max(settingsInterface2[i].size(), maxSize);

	for (int i = 0; i < interface1Size2; i++) {
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << "                                 ";
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface2[i];
	}

	while (1)
	{

		SetConsoleTextAttribute(hC, activeColor);

		if (cursoreLine != interface1Size2 - 1)ShowConsoleCursor(1);
		else ShowConsoleCursor(0);

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + lastCursore * 3 + 8);
		cout << "   " << settingsInterface2[lastCursore];

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + cursoreLine * 3 + 8);
		cout << ">> ";
		cout << settingsInterface2[cursoreLine];

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3+8);
		tapp = _getch();

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
		cout << "                                                 ";
		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);


		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size2, cursoreLine, tapp);
		}
		else if (((tapp >= 65 && tapp <= 122 && cursoreLine != interface1Size2-1) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46) && cursoreLine != interface1Size2-1)
		{
			newSettings[cursoreLine] = newSettings[cursoreLine] + static_cast<char>(tapp);
			cout << static_cast<char>(tapp);
		}
		else if (tapp == 8 && newSettings[cursoreLine] != "")
		{
			newSettings[cursoreLine].pop_back();
			setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
			cout << " ";
		}
		else if (tapp == 41)
		{
			setCursorPosition(1, 1);
			cout << newSettings[cursoreLine] << endl;
		}
		else if ((tapp == 13 && cursoreLine == 3) || tapp == 52)
		{
			readUserBase();
			int log=-1, code=-1, passord=-1;
			for (int i = 0; i < 3; i++)
			{
				if (settingsInterface2[i] == "�����:      ") log = i;
				if (settingsInterface2[i] == "������:     ") passord = i;
				if (settingsInterface2[i] == "��� �������:") code = i;
			}
			userInSystem = -1;
			for (USER_SETTINGS a : userSetting)
			{
				userInSystem++;
				if(log!=-1)
					if(newSettings[log] == a.login2 && a.login2!="")
						if (newSettings[passord] == a.password2 || newSettings[code] == a.codeIn2)
						{
							if (a.role2 == "Admin") adminMenu();
							else userMenu();
							goto SYDA;
						}
				if(code!=-1)
					if (newSettings[code] == a.codeIn2 && a.codeIn2 != "")
					{
						if (a.role2 == "Admin") adminMenu();
						else userMenu();
						goto SYDA;
					}
			}

			if (userInSystem > sizeUserSettings)
			{
				setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
				SetConsoleTextAttribute(hC, lastColor);
				cout << "������ �����";
			}
		SYDA:
			Sleep(1);
		}
		else if (tapp == 27)
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size2+1; i++) {
				setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                ";
			}
			break;
		}
	}
}


void userMenu()
{
	system("color 7a");
}
void adminMenu()
{

}

void newSettings()
{
	setting = readSettingsFile();

	if (setting.theme == "LIGHT")
	{
		system("color 70");
		activeColor = 112;
		lastColor = 120;
	}
	else if (setting.theme == "BLUE")
	{
		system("color 1F");
		activeColor = 31;
		lastColor = 24;
	}
	else
	{
		system("color 0e");
		activeColor = 14;
		lastColor = 6;
	}
	nameController(setting.title);
}
void readUserBase()
{
	ofstream read("Data/users.txt", ios::app);
	read.close();
	ifstream read2("Data/users.txt");

	string theme2;
	string login2;
	string password2;
	string codeIn2;
	string role2;
	string age2;
	string specialization2;
	string sex2;
	string personalChar2[4];
	string customizableChar[5];

	int card;

	while (!read2.eof())
	{
		read2 >> theme2 >> login2 >> password2 >> codeIn2 >> role2 >> age2 >> specialization2 >> sex2
			>> personalChar2[0] >> personalChar2[1] >> personalChar2[2] >> personalChar2[3]
			>> customizableChar[0] >> customizableChar[1] >> customizableChar[2] >> customizableChar[3] >> customizableChar[4]
			>>card;

		userSetting[sizeUserSettings].setAll(theme2, login2, password2, codeIn2, role2, age2, specialization2, sex2, personalChar2, customizableChar,card);
		sizeUserSettings++;
	}
}
