#include "Header.h"

CHORDS chords = getConsleChords();
string master = "МАСТЕР НАСТРОЕК";
string ex = "esc для выхода";

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SETTINGS myCorporation;

void masterOfSettings()
{
	system("cls");
	myCorporation.setAllAdminFunc(0, 0, 0, 0);
	myCorporation.setBaseFunc1("DARK ", 0);
	myCorporation.setUserCard1(0, 0, 0, 0);
		
	startMasterDraw();

	//settingMenu_1();
	settingMenu_2();

	ShowConsoleCursor(1);
}

void startMasterDraw()
{
	chords = getConsleChords();

	setCursorPosition(chords.x / 2 - master.size() / 2, 1);
	SetConsoleTextAttribute(hConsole, 14);
	cout << master;

	setCursorPosition(1, 1);
	cout << ex;
	SetConsoleTextAttribute(hConsole, 6);
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
		
		if(cursoreLine != interface1Size-1)ShowConsoleCursor(1);
		else ShowConsoleCursor(0);

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
		else if (((tapp >= 65 && tapp <= 122 && cursoreLine != 4) || (tapp >=48 && tapp<=57) || tapp == 64 || tapp == 46) && cursoreLine != 4)
		{
			
			newSettings[cursoreLine] = newSettings[cursoreLine] + static_cast<char>(tapp);
			
			if (cursoreLine == 2 || cursoreLine == 3)
			{
				cout << "*";
			}
			else cout << static_cast<char>(tapp);
		}
		else if (tapp == 8 && newSettings[cursoreLine] != "")
		{
			newSettings[cursoreLine].pop_back();
			setCursorPosition(chords.x / 4 + (maxSize + 3) + newSettings[cursoreLine].length(), 3 + chords.y / 4 + cursoreLine * 3);
			cout << " ";
		}
		else if (tapp == 41)
		{
			setCursorPosition(1, 1);
			cout << newSettings[cursoreLine] << endl;
		}
		else if (tapp == 13 && cursoreLine == 4)
		{
			setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 - 2);
			cout << "                                                               ";
			setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 - 2);
			SetConsoleTextAttribute(hConsole, 2);
			cout << "ДАННЫЕ ОБРАБАТЫВАЮТСЯ";
			Sleep(800);
			if (isValidEmail(newSettings[1]))
			{
				if (newSettings[2] == newSettings[3] && newSettings[3].size() > 3)
				{
					setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 - 2);
					cout << "                                                               ";
					setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 - 2);
					SetConsoleTextAttribute(hConsole, 10);
					cout << "ЗАПРОС ОДОБРЕН";
					Sleep(800);

					myCorporation.setAllPartOne(newSettings[0], newSettings[1], newSettings[2]);
					break;
				}
				else goto SYDA;
			}
			else
			{
			SYDA:
				setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 - 2);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "НАЙДЕНА ОШИБКА. ИЗМЕНИТЕ ДАННЫЕ";
				SetConsoleTextAttribute(hConsole, 6);
				setCursorPosition(chords.x / 4 - 3, 3 + chords.y / 4 + lastCursore * 3);

			}
		}
		else if (tapp == 27)
		{
			leave();
		}
	}
}
void settingMenu_2()
{
	ShowConsoleCursor(0);

	system("cls");
	chords = getConsleChords();

	startMasterDraw();


	const int sizeMain = 3;

	const int sizeAutor = 3;
	const int sizeTempl = 7;
	const int sizeRole = 5;
	const int sizeRoleSettings = 3;
	int tapp = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;


	string setting2_Main[sizeMain] = {"Объект","Администраия","Продолжить"};

	string setting2_Templates[sizeTempl] = { "Роль", "Возраст", "Специализация", "Логин", "Код доступа", "Пароль" , "Пол" };
	string setting2_Role[sizeRole] = {"","","","",""};
	string setting2_Role_Settings[sizeRoleSettings] = { "Работа с занятостью", "Просмотр занятых", "Название файла:" };


	for (int i = 0; i < sizeMain; i++) {
		setCursorPosition(chords.x / 5, 3 + chords.y / 5 + i * 3);
		cout << setting2_Main[i];
	}

	for (int i = 0; i < sizeMain; i++) maxSize = max(setting2_Main[i].size(), maxSize);

	

	while (1)
	{
		setCursorPosition(chords.x / 5 - 3, 3 + chords.y / 5 + lastCursore * 3);
		SetConsoleTextAttribute(hConsole, 6);
		cout << "   " << setting2_Main[lastCursore];

		setCursorPosition(chords.x / 5 - 3, 3 + chords.y / 5 + cursoreLine * 3);
		SetConsoleTextAttribute(hConsole, 14);
		cout << ">> " << setting2_Main[cursoreLine];

		setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3);

		SetConsoleTextAttribute(hConsole, 6);
		if (cursoreLine == 0) { deleteZone(maxSize + chords.x/5); drawObjects(tapp); }
		else if (cursoreLine == 1) { deleteZone(maxSize + chords.x / 5); drawAdmin(tapp); }
		else if (cursoreLine == 2) { deleteZone(maxSize + chords.x / 5); }

		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(sizeMain, cursoreLine, tapp);
		}
		else if (tapp == 27)
		{
			leave();
		}
	}
}

void drawObjects(int code)
{
	const int sizeObject = 4;
	int maxSize = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int tapp = 0;

	string setting2_Object[sizeObject] = { "Общие настройки", "Авторизаия", "Шаблон", "Роли" };

	for (int i = 0; i < sizeObject; i++) {
		setCursorPosition(chords.x / 5 + 23, 3 + chords.y / 5 + i * 3+1);
		cout << setting2_Object[i];
	}

	for (int i = 0; i < sizeObject; i++) maxSize = max(setting2_Object[i].size(), maxSize);
	if (code == 77)
		while (1)
		{
			setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + lastCursore * 3 + 1);
			SetConsoleTextAttribute(hConsole, 6);
			cout << "   " << setting2_Object[lastCursore];

			setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + cursoreLine * 3 +1);
			SetConsoleTextAttribute(hConsole, 11);
			cout << ">> " << setting2_Object[cursoreLine];

			setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3 + 1);

			if (cursoreLine == 0) { deleteZone(maxSize + chords.x / 3);  drawBase(tapp); }
			else if (cursoreLine == 1) { deleteZone(maxSize + chords.x / 3); drawAutor(tapp); }
			else if (cursoreLine == 2) { deleteZone(maxSize + chords.x / 3); drawTempl(tapp); }
			else if (cursoreLine == 3) { deleteZone(maxSize + chords.x / 3); drawRole(); }


			tapp = _getch();

			if (tapp == 80 || tapp == 72)
			{
				lastCursore = cursoreLine;
				cursoreLine = gotoThisLine(sizeObject, cursoreLine, tapp);
			}
			else if (tapp == 75)
			{
				setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + cursoreLine * 3 + 1);
				SetConsoleTextAttribute(hConsole, 6);
				cout << "   " << setting2_Object[cursoreLine];
				break;
			}
		}
}

void drawAdmin(int code)
{
	const int sizeAdmin = 4;
	int tapp;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;


	string setting2_admin[sizeAdmin] = { "] Изменение темы", "] Корректировка БД", "] Корректировка ЛК", "] Временные коды доступа" };
	string yes ="<   ПОДКЛЮЧЕНО  >";
	string no = "< НЕ ПОДКЛЮЧЕНО >";


	for (int i = 0; i < sizeAdmin; i++) maxSize = max(setting2_admin[i].size(), maxSize);

	for (int i = 0; i < sizeAdmin; i++) {
		setCursorPosition(chords.x / 5 + 23 + maxSize+2, 3 + chords.y / 5 + i * 3 + 1);
		if (i == 0) if (!myCorporation.correctTheme ? cout << no : cout << yes);
		if (i == 1) if (!myCorporation.correctDB  ? cout << no : cout << yes);
		if (i == 2) if (!myCorporation.correctCab ? cout << no : cout << yes);
		if (i == 3) if (!myCorporation.temporaryPassord ? cout << no : cout << yes);
	}

	for (int i = 0; i < sizeAdmin; i++) {
		setCursorPosition(chords.x / 5 + 23, 3 + chords.y / 5 + i * 3 + 1);
		cout << setting2_admin[i];
	}

	if (code == 77)
		while (1)
		{
			setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + lastCursore * 3 + 1);
			SetConsoleTextAttribute(hConsole, 6);
			cout << "   " << setting2_admin[lastCursore];

			setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + cursoreLine * 3 + 1);
			SetConsoleTextAttribute(hConsole, 11);
			cout << ">> " << setting2_admin[cursoreLine];

			setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3 + 1);
			for (int i = 0; i < sizeAdmin; i++) {
				SetConsoleTextAttribute(hConsole, 14);
				setCursorPosition(chords.x / 5 + 23 + maxSize + 2, 3 + chords.y / 5 + i * 3 + 1);
				if (i == 0) if (!myCorporation.correctTheme ? cout << no : cout << yes);
				if (i == 1) if (!myCorporation.correctDB ? cout << no : cout << yes);
				if (i == 2) if (!myCorporation.correctCab ? cout << no : cout << yes);
				if (i == 3) if (!myCorporation.temporaryPassord ? cout << no : cout << yes);
			}

			tapp = _getch();

			if (tapp == 80 || tapp == 72)
			{
				lastCursore = cursoreLine;
				cursoreLine = gotoThisLine(sizeAdmin, cursoreLine, tapp);
			}
			else if (tapp == 75)
			{
				setCursorPosition(chords.x / 5 - 3 + 23, 3 + chords.y / 5 + cursoreLine * 3 + 1);
				SetConsoleTextAttribute(hConsole, 6);
				cout << "   " << setting2_admin[cursoreLine];
				break;
			}
			else if (tapp == 13 || tapp ==77)
			{
				if (cursoreLine == 0) if (!myCorporation.correctTheme ? myCorporation.correctTheme=true : myCorporation.correctTheme=false);
				if (cursoreLine == 1) if (!myCorporation.correctDB ? myCorporation.correctDB = true : myCorporation.correctDB = false);
				if (cursoreLine == 2) if (!myCorporation.correctCab ? myCorporation.correctCab = true : myCorporation.correctCab = false);
				if (cursoreLine == 3) if (!myCorporation.temporaryPassord ? myCorporation.temporaryPassord = true : myCorporation.temporaryPassord = false);
			}
		}

}

void deleteZone(int maxSizeX)
{
	for (int i = chords.y/5; i < chords.y/2; i++)
	{
		setCursorPosition(maxSizeX, i);
		for (int y = 0; y < chords.x - (maxSizeX)-1; y++)printf(" ");
	}
}

void drawBase(int code)
{
	int tapp = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;
	const int sizeBase = 2;

	int num = 1;

	string setting2_Base[sizeBase] = { "] Тема", "] Настроить профиль" };
	string yes = "<   ПОДКЛЮЧЕНО  >";
	string no = "< НЕ ПОДКЛЮЧЕНО >";


	for (int i = 0; i < sizeBase; i++) maxSize = max(setting2_Base[i].size(), maxSize);

	for (int i = 0; i < sizeBase; i++)
	{
		SetConsoleTextAttribute(hConsole, 6);
		setCursorPosition(chords.x / 5 + 28 + maxSize + 2, 3 + chords.y / 5 + i * 3 + 2);
		cout << setting2_Base[i];
	}

	for (int i = 0; i < sizeBase; i++)
	{
		SetConsoleTextAttribute(hConsole, 6);
		setCursorPosition(chords.x / 5 + 44 + maxSize + 7, 3 + chords.y / 5 + i * 3 + 2);
		if (i == 0) cout << "< " << myCorporation.theme << " >";
		if (i == 1)if (!myCorporation.profileCorrect ? cout << no : cout << yes);
	}

	if (code == 77)
		while (1)
		{

			for (int i = 0; i < sizeBase; i++)
			{
				SetConsoleTextAttribute(hConsole, 14);
				setCursorPosition(chords.x / 5 + 44 + maxSize + 7, 3 + chords.y / 5 + i * 3 + 2);
				if (i == 0) cout << "< " << myCorporation.theme << " >";
				if (i == 1)if (!myCorporation.profileCorrect ? cout << no : cout << yes);
			}
			setCursorPosition(chords.x / 5 + 28 + maxSize + 2 -3, 3 + chords.y / 5 + lastCursore * 3 + 2);
			SetConsoleTextAttribute(hConsole, 6);
			cout << "   " << setting2_Base[lastCursore];

			setCursorPosition(chords.x / 5 + 28 + maxSize + 2 -3, 3 + chords.y / 5 + cursoreLine * 3 + 2);
			SetConsoleTextAttribute(hConsole, 14);
			cout << ">> " << setting2_Base[cursoreLine];

			//setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3 + 1);


			tapp = _getch();

			if (tapp == 80 || tapp == 72)
			{
				lastCursore = cursoreLine;
				cursoreLine = gotoThisLine(sizeBase, cursoreLine, tapp);
			}
			else if (tapp == 75)
			{
				setCursorPosition(chords.x / 5 - 3 + 28 + maxSize + 2, 3 + chords.y / 5 + cursoreLine * 3 + 2);
				SetConsoleTextAttribute(hConsole, 6);
				cout << "   " << setting2_Base[cursoreLine];
				break;
			}
			else if (tapp == 13 || tapp == 77)
			{
				if (cursoreLine == 0) 
				{
					num++;
					if (num == 0 || num > 2) {myCorporation.theme = "LIGHT"; }					
					else if (num == 1) myCorporation.theme = "DARK ";
					else if (num == 2) { myCorporation.theme = "BLUE "; num = -1; }
				}
				else if (!myCorporation.profileCorrect ? myCorporation.profileCorrect = true : myCorporation.profileCorrect = false);
			}
		}
}

void drawAutor(int code)
{
	const int sizeAutor = 3;
	int tapp;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;


	string setting2_Authorization[sizeAutor] = { "] Логин", "] Пароль","] Код доступа" };
	string yes = "<   ПОДКЛЮЧЕНО  >";
	string no = "< НЕ ПОДКЛЮЧЕНО >";


	for (int i = 0; i < sizeAutor; i++) maxSize = max(setting2_Authorization[i].size(), maxSize);

	SetConsoleTextAttribute(hConsole, 6);

	for (int i = 0; i < sizeAutor; i++) {
		setCursorPosition(chords.x / 5 + 49 + maxSize + 7, 3 + chords.y / 5 + i * 3 + 2);
		if (i == 0) if (!myCorporation.login ? cout << no : cout << yes);
		if (i == 1) if (!myCorporation.password ? cout << no : cout << yes);
		if (i == 2) if (!myCorporation.codeIn ? cout << no : cout << yes);
	}

	for (int i = 0; i < sizeAutor; i++) {
		setCursorPosition(chords.x / 5 + 49, 3 + chords.y / 5 + i * 3 + 2);
		cout << setting2_Authorization[i];
	}

	if (code == 77)
		while (1)
		{
			setCursorPosition(chords.x / 5 + 33 + maxSize , 3 + chords.y / 5 + lastCursore * 3 + 2);
			SetConsoleTextAttribute(hConsole, 6);
			cout << "   " << setting2_Authorization[lastCursore];

			setCursorPosition(chords.x / 5 + 33 + maxSize , 3 + chords.y / 5 + cursoreLine * 3 + 2);
			SetConsoleTextAttribute(hConsole, 14);
			cout << ">> " << setting2_Authorization[cursoreLine];

			setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3 + 2);
			for (int i = 0; i < sizeAutor; i++) {
				SetConsoleTextAttribute(hConsole, 14);
				setCursorPosition(chords.x / 5 + 50 + maxSize + 7, 3 + chords.y / 5 + i * 3 + 2);
				if (i == 0) if (!myCorporation.login ? cout << no : cout << yes);
				if (i == 1) if (!myCorporation.password ? cout << no : cout << yes);
				if (i == 2) if (!myCorporation.codeIn ? cout << no : cout << yes);
			}

			tapp = _getch();

			if (tapp == 80 || tapp == 72)
			{
				lastCursore = cursoreLine;
				cursoreLine = gotoThisLine(sizeAutor, cursoreLine, tapp);
			}
			else if (tapp == 75)
			{
				setCursorPosition(chords.x / 5 + 33 + maxSize, 3 + chords.y / 5 + cursoreLine * 3 + 2);
				SetConsoleTextAttribute(hConsole, 6);
				cout << "   " << setting2_Authorization[cursoreLine];
				break;
			}
			else if (tapp == 13 || tapp == 77)
			{
				if (cursoreLine == 0) if (!myCorporation.login ? myCorporation.login = true : myCorporation.login = false);
				if (cursoreLine == 1) if (!myCorporation.password ? myCorporation.password = true : myCorporation.password = false);
				if (cursoreLine == 2) if (!myCorporation.codeIn ? myCorporation.codeIn = true : myCorporation.codeIn = false);
			}
		}

}

void drawTempl(int code)
{

}

void drawRole()
{

}