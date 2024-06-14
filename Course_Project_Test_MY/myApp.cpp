#include "Header.h"

SETTINGS setting;
CHORDS chord = getConsleChords();
HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);

USER_SETTINGS userSetting[10000];
int sizeUserSettings = 0;

PRODUCT product[10000];
int sizeProductBase = 0;
int activeColor;
int lastColor;

int userInSystem = -1;


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

		string settingsInterface1[interface1Size] = { "1. Войти","2. Зарегестрироваться","3. Информация", "4. Выход" };

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


			setCursorPosition(chord.x / 4 + (maxSize + 3), 3 + chord.y / 4 + cursoreLine * 3);
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
			else if (tapp == 13)
			{
				if (cursoreLine == 0) { entrance(); }
				if (cursoreLine == 1) { reg(); }
				if (cursoreLine == 2) { inf(); }
			}
			else if (tapp == 49)entrance();
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
	string settingsInterface1[interface1Size] = { "КОНТАКТЫ","    Название: ","    Почта:    ","", "Приложение основано на ПО \"Work Wave\"", "\tлицензия Pyt.Tech 2024-NOW" };

	for (int i = 0; i < interface1Size - 2; i++) maxSize = max(settingsInterface1[i].size(), maxSize);
	for (int i = 0; i < interface1Size; i++) {
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface1[i];
		if (i == 1) cout << " " << setting.title;
		if (i == 2)cout << " " << setting.email;
		if (i == interface1Size - 3 || i == interface1Size - 2)	SetConsoleTextAttribute(hC, lastColor);
		else SetConsoleTextAttribute(hC, activeColor);
	}
	_getch();
	system("cls");
	newSettings();
}

void reg()
{
	const int interface1Size = 4;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;

	string settingsInterface1[interface1Size] = { "Логин:        ", "Пароль:       ", "Специализация:", "Далее ->" };
	string newSettings[interface1Size] = { "","","" };


	for (int i = 0; i < interface1Size; i++)maxSize = max(settingsInterface1[i].size(), maxSize);

	for (int i = 0; i < interface1Size; i++) {
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << "                                 ";
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface1[i];
	}

	while (1)
	{

		SetConsoleTextAttribute(hC, activeColor);

		if (cursoreLine != interface1Size - 1)ShowConsoleCursor(1);
		else ShowConsoleCursor(0);

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + lastCursore * 3 + 8);
		cout << "   " << settingsInterface1[lastCursore];

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + cursoreLine * 3 + 8);
		cout << ">> ";
		cout << settingsInterface1[cursoreLine];

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
		tapp = _getch();

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
		cout << "                                                 ";
		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);


		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if (((tapp >= 65 && tapp <= 122 && cursoreLine != interface1Size - 1) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46) && cursoreLine != interface1Size - 1)
		{
			newSettings[cursoreLine] = newSettings[cursoreLine] + char(tapp);
			cout << char(tapp);
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

			userInSystem = -1;
			for (USER_SETTINGS a : userSetting)
			{
				if (a.login2 == newSettings[0]) { userInSystem = 20000; break; }
			}

			if (userInSystem > sizeUserSettings)
			{
				setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
				SetConsoleTextAttribute(hC, lastColor);
				cout << "ОШИБКА РЕГИСТРАЦИИ этап 1";
			}
			else
			{
				userSetting[900].login2 = newSettings[0];
				userSetting[900].password2 = newSettings[1];
				userSetting[900].specialization2 = newSettings[2];
				reg2();

				for (int i = 0; i < interface1Size + 1; i++) {
					setCursorPosition(chord.x / 2, 3 + chord.y / 4 + i * 3 + 8);
					cout << "                                                                                                        ";
				}
				break;
				break;
			}


		}
		else if (tapp == 27)
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x / 2, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                                                                        ";
			}
			break;
		}
	}
}
void reg2()
{
	const int interface1Size = 4;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;
	int numRole = 0;

	string settingsInterface1[interface1Size] = { "Возраст:", "] Роль: ", "] Пол:  ", "Подтвердить" };
	string newSettings[interface1Size] = { "","","" };
	userSetting[900].role2 = setting.customizableChar[0];
	userSetting[900].sex2 = "М";
	userSetting[900].theme2 = "1";


	for (int i = 0; i < interface1Size; i++)maxSize = max(settingsInterface1[i].size(), maxSize);

	for (int i = 0; i < interface1Size; i++) {
		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
		cout << "                                 ";
		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface1[i];
		if (i == 1) cout << userSetting[900].role2;
		if (i == 2) cout << userSetting[900].sex2;
	}

	while (1)
	{

		SetConsoleTextAttribute(hC, activeColor);

		if (cursoreLine != interface1Size - 1)ShowConsoleCursor(1);
		else ShowConsoleCursor(0);

		setCursorPosition(chord.x - maxSize - 25 - 3, 3 + chord.y / 4 + lastCursore * 3 + 8);
		cout << "   " << settingsInterface1[lastCursore];
		//if (cursoreLine == 1) cout << userSetting[0].role2;
		if (cursoreLine == 1) {
			setCursorPosition(chord.x - maxSize - 25 - 3, 3 + chord.y / 4 + cursoreLine * 3 + 8);
			cout << "                                          ";
		}
		setCursorPosition(chord.x - maxSize - 25 - 3, 3 + chord.y / 4 + cursoreLine * 3 + 8);
		cout << ">> ";
		cout << settingsInterface1[cursoreLine];
		if (cursoreLine == 1) cout << userSetting[900].role2;
		if (cursoreLine == 2) cout << userSetting[900].sex2;


		if (cursoreLine == 0)
			setCursorPosition(chord.x + maxSize + newSettings[cursoreLine].length(), chord.y / 4 + cursoreLine * 3 + 8);
		else
			setCursorPosition(chord.x + maxSize, chord.y / 4 + cursoreLine * 3 + 8);

		tapp = _getch();




		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if (tapp >= 48 && tapp <= 57 && cursoreLine == 0)
		{
			setCursorPosition(chord.x + maxSize - 25 + newSettings[cursoreLine].size(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
			if (cursoreLine != 0)newSettings[cursoreLine] = newSettings[cursoreLine] + static_cast<char>(tapp);
			else { 
				newSettings[cursoreLine] = newSettings[cursoreLine];   newSettings[cursoreLine].push_back(char(tapp));
			}
			if (cursoreLine != 0) cout << char(tapp);
			else cout << char(tapp);
		}
		else if (tapp == 8 && newSettings[cursoreLine] != "")
		{
			newSettings[cursoreLine].pop_back();
			setCursorPosition(chord.x + maxSize - 25 + newSettings[cursoreLine].size(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
			cout << " ";
		}
		else if (tapp == 41)
		{
			setCursorPosition(1, 1);
			cout << newSettings[cursoreLine] << endl;
		}
		else if (cursoreLine == 1 && tapp == 77)
		{
			numRole++;
			if (numRole == setting.sizeCustomizable) numRole = 0;
			userSetting[900].role2 = setting.customizableChar[numRole];
		}
		else if (cursoreLine == 2 && tapp == 77)
		{
			if (userSetting[900].sex2 == "М")userSetting[900].sex2 = "Ж";
			else userSetting[900].sex2 = "М";
		}
		else if ((tapp == 13 && cursoreLine == 3) || tapp == 52)
		{
			readUserBase();

			userSetting[900].age2 = newSettings[0];
			userSetting[900].codeIn2 = generateRandomString(10);
			ofstream a("Data/users.txt", ios::app);
			a << userSetting[900].getAll() << endl;

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x / 2, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                                                                        ";
			}
			break;
		}
		else if (tapp == 27)
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x / 2, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                                                                        ";
			}
			break;
		}
	}
}
void entrance()
{
	const int interface1Size = 4;
	int interface1Size2 = 0;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;

	string settingsInterface1[interface1Size] = { "Логин:      ", "Пароль:     ", "Код доступа:", "Войти" };
	string settingsInterface2[interface1Size] = { "", "", "", "Войти" };
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

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
		tapp = _getch();

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
		cout << "                                                 ";
		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);


		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size2, cursoreLine, tapp);
		}
		else if (((tapp >= 65 && tapp <= 122 && cursoreLine != interface1Size2 - 1) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46) && cursoreLine != interface1Size2 - 1)
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
			int log = -1, code = -1, passord = -1;
			for (int i = 0; i < 3; i++)
			{
				if (settingsInterface2[i] == "Логин:      ") log = i;
				if (settingsInterface2[i] == "Пароль:     ") passord = i;
				if (settingsInterface2[i] == "Код доступа:") code = i;
			}
			userInSystem = -1;
			for (USER_SETTINGS a : userSetting)
			{
				userInSystem++;
				if (code != -1)
					if (newSettings[code] == a.codeIn2 && a.codeIn2 != "")
					{
						if (a.role2 == "Admin") adminMenu();
						else userMenu();
						goto SYDA;
					}
				if (log != -1)
				{
					if (newSettings[log] == a.login2 && a.login2 != "")
						if (newSettings[passord] == a.password2 || newSettings[code] == a.codeIn2)
						{
							if (a.role2 == "Admin") adminMenu();
							else userMenu();
							goto SYDA;


						}
					if (newSettings[code] == a.codeIn2 && a.codeIn2 != "")
					{
						if (a.role2 == "Admin") adminMenu();
						else userMenu();
						goto SYDA;

					}
				}

			}

			if (userInSystem > sizeUserSettings)
			{
				setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
				SetConsoleTextAttribute(hC, lastColor);
				cout << "ОШИБКА ВХОДА";
			}
			if (3 == 2) {
			SYDA:
				break;
			}
		}
		else if (tapp == 27)
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size2 + 1; i++) {
				setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                ";
			}
			break;
		}
	}
}


void userMenu()
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

	string settingsInterface1[interface1Size] = { "1. Работа","2. Мои места","3. Личный кабинет", "4. Выход" };

	for (int i = 0; i < interface1Size; i++) maxSize = max(settingsInterface1[i].size(), maxSize);



	while (1)
	{
		nameController(setting.title);

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


		setCursorPosition(chord.x / 4 + (maxSize + 3), 3 + chord.y / 4 + cursoreLine * 3);
		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if (tapp == 27 || tapp == 52 || (cursoreLine == interface1Size - 1 && tapp == 13))
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                ";
			}
			break;
		}
		else if (tapp == 13)
		{
			if (cursoreLine == 0) { job(0); }
			if (cursoreLine == 1) { myJob(0); }
			if (cursoreLine == 2) { myCab(0); }
		}
		else if (tapp == 49)job(0);
		else if (tapp == 50)myJob(0);
		else if (tapp == 51)myCab(0);

	}
}

void job(int num)
{
	string line = "";
	string fuck = "Номер понравившейся вакансии: ";
	while (1)
	{
		system("cls");
		readProductBase();
		if (sizeProductBase / 5 != 0) sizeProductBase++;

		setCursorPosition(chord.x - 56, 5);
		cout << fuck << line;
		setCursorPosition(chord.x - 56 + line.size() + fuck.size(), 5);

		//cout << sizeProductBase;
		//cout << endl << num;
		if (sizeProductBase == 0) { cout << "Вакансии отсутствуют"; }

		if (num == 0) {
			if (sizeProductBase < 5) {
				for (int i = 0; i < sizeProductBase; i++) {

					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * i);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "        |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * i);
					cout << "|                 |" << "----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * i);
					cout << "|_________________|__________________________________|\n";
				}
			}

			else {
				for (int i = 0; i < 5; i++) {


					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * i);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * i);
					cout << "|                 |" << "----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * i);
					cout << "|_________________|__________________________________|\n";

				}
			}
		}
		else {
			int fulllist = sizeProductBase / 5;
			int costrat = sizeProductBase - fulllist * 5;
			int counter = 0;
			if (costrat == 0) { costrat = 5; }

			if (sizeProductBase < (num + 1) * 5) {

				for (int i = num * 5; counter < costrat; i++) {

					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * counter);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * counter);
					cout << "|                 |----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * counter);
					cout << "|_________________|__________________________________|\n";
					counter++;
				}

			}
			else {
				for (int i = num * 5; counter < 5; i++) {
					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * counter);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * counter);
					cout << "|                 |----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";
					;

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";


					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * counter);
					cout << "|_________________|__________________________________|\n";
					counter++;
				}

			}
		}

		setlocale(LC_ALL, "en_US.UTF-8");
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		if (num != 0)
		{
			setCursorPosition(3, chord.y - 2);
			cout << u8"░░██╗";
			setCursorPosition(3, chord.y - 1);
			cout << u8"░██╔╝";
			setCursorPosition(3, chord.y);
			cout << u8"██╔╝░";
			setCursorPosition(3, chord.y + 1);
			cout << u8"╚██╗░";
			setCursorPosition(3, chord.y + 2);
			cout << u8"░╚██╗";
			setCursorPosition(3, chord.y + 3);
			cout << u8"░░╚═╝";
		}
		if (num != sizeProductBase / 5)
		{
			setCursorPosition(chord.x * 1.6, chord.y -2);
			cout << u8"██╗░░";
			setCursorPosition(chord.x * 1.6, chord.y - 1);
			cout << u8"╚██╗░";
			setCursorPosition(chord.x * 1.6, chord.y );
			cout << u8"░╚██╗";
			setCursorPosition(chord.x * 1.6, chord.y + 1);
			cout << u8"░██╔╝";
			setCursorPosition(chord.x * 1.6, chord.y + 2);
			cout << u8"██╔╝░";
			setCursorPosition(chord.x * 1.6, chord.y + 3);
			cout << u8"╚═╝░░";
		}
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		int a = _getch();
		if (a == 75) {
			num--;
			if (num < 0)num++;
		}
		else if (a == 77) {
			num++;
			//if (num > (sizeProductBase+4)/5 -1)num--;
			if (num * 5 > sizeProductBase)num--;
		}
		else if (a == 27)
		{
			system("cls");
			setting = readSettingsFile();
			break;
		}
		else if (a >= 48 && a <= 57)
		{
			setCursorPosition(chord.x - 56 + line.size() + fuck.size(), 15);
			line = line + static_cast<char>(a);
			cout << static_cast<char>(a);	
		}
		else if (a == 8 && line != "")
		{
			line.pop_back();
			setCursorPosition(chord.x - 56 + line.size(), 5);
			cout << " ";
		}
		else if (a == 13 && line != "")
		{
			if (stoi(line) >= 0 && stoi(line) <= sizeProductBase)
			thisProduct(stoi(line));
		}
	}
}

void thisProduct(int num)
{
	int tapp = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;
	const int sizeBase = 2;

	system("cls");

	nameController(product[num].name);

	string setting2_Base[sizeBase] = { "1. Откликнуться", "2. Назад" };
	for (int i = 0; i < sizeBase; i++) maxSize = max(setting2_Base[i].size(), maxSize);


	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 +5);  cout << "Тип занятости: " << product[num].type;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 8); cout << "Спеиальность:  " << product[num].profession;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 11);cout << "Опыт:          " << product[num].exp;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 14);cout << "Время работы:  " << product[num].from<<" - "<< product[num].to;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 17);cout << "Адрес:         " << product[num].adress;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 20);cout << "Зарплата:      " << product[num].salary;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 25);cout << "Вакансию создал: " << product[num].login;
	setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 27);cout << "Номер для связи: " << product[num].contacts;

	for (int i = 0; i < sizeBase; i++)
	{
		SetConsoleTextAttribute(hC, lastColor);
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 5 + i * 3 + 2);
		cout << setting2_Base[i];
	}


	while (1)
	{

		for (int i = 0; i < sizeBase; i++)
		{
			SetConsoleTextAttribute(hC, activeColor);
			setCursorPosition(chord.x / 5 + 44 + maxSize + 7, 3 + chord.y / 5 + i * 3 + 2);

		}
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 5 + lastCursore * 3 + 2);
		SetConsoleTextAttribute(hC, lastColor);
		cout << "   " << setting2_Base[lastCursore];

		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 5 + cursoreLine * 3 + 2);
		SetConsoleTextAttribute(hC, activeColor);
		cout << ">> " << setting2_Base[cursoreLine];

		//setCursorPosition(chords.x / 5 + (maxSize + 3), 3 + chords.y / 5 + cursoreLine * 3 + 1);


		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(sizeBase, cursoreLine, tapp);
		}
		else if (tapp == 27 || (cursoreLine == 1 && tapp==13) ||(tapp == 50))
		{
			system("cls");
			break;
		}
		else if ((tapp == 13 && cursoreLine == 0) || (tapp == 49))
		{
			ofstream link("Data/link.txt", ios::app);
			link << product[num].login << " " << userSetting[userInSystem].login2 << " " << product[num].name << endl;
			link.close();
			setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + 30);
			SetConsoleTextAttribute(hC, lastColor);
			cout << "Связь создана!";
			_getch();
			SetConsoleTextAttribute(hC, activeColor);
			break;
		}
	}
}

void myJob(int num)
{
	string line = "";
	string fuck = "Номер вакансии для подробного просмотра : ";
	string text ="! - добавить новую вакансию\n" ;
	while (1)
	{
		system("cls");
		readProductBase(userSetting[userInSystem].login2);
		if (sizeProductBase / 5 != 0) sizeProductBase++;

		setCursorPosition(chord.x - 56, 3);
		cout << text;
		setCursorPosition(chord.x - 56, 5);
		cout << fuck << line;
		setCursorPosition(chord.x - 56 + line.size() + fuck.size(), 5);

		//cout << sizeProductBase;
		//cout << endl << num;
		if (sizeProductBase == 0) { cout << "Вакансии отсутствуют"; }

		if (num == 0) {
			if (sizeProductBase < 5) {
				for (int i = 0; i < sizeProductBase; i++) {

					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * i);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "        |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * i);
					cout << "|                 |" << "----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * i);
					cout << "|_________________|__________________________________|\n";
				}



			}

			else {
				for (int i = 0; i < 5; i++) {


					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * i);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * i);
					cout << "|                 |" << "----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * i);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * i);
					cout << "|_________________|__________________________________|\n";

				}
			}
		}
		else {
			int fulllist = sizeProductBase / 5;
			int costrat = sizeProductBase - fulllist * 5;
			int counter = 0;
			if (costrat == 0) { costrat = 5; }

			if (sizeProductBase < (num + 1) * 5) {

				for (int i = num * 5; counter < costrat; i++) {

					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * counter);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * counter);
					cout << "|                 |----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";

					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * counter);
					cout << "|_________________|__________________________________|\n";
					counter++;
				}

			}
			else {
				for (int i = num * 5; counter < 5; i++) {
					setCursorPosition(chord.x - 56, 3 + chord.y / 8 + 8 + 10 * counter);
					cout << "_/==================================================\\_\n";

					setCursorPosition(chord.x - 56, 4 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].name << "| #" << setw(3) << i << setw(31) << "       |\n";

					setCursorPosition(chord.x - 56, 5 + chord.y / 8 + 8 + 10 * counter);
					cout << "|                 |----------------------------------|\n";

					setCursorPosition(chord.x - 56, 6 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].profession << "| Адрес:" << setw(26) << product[i].adress << " |\n";
					;

					setCursorPosition(chord.x - 56, 7 + chord.y / 8 + 8 + 10 * counter);
					cout << "| " << setw(16) << product[i].salary << "| Опыт:" << setw(27) << product[i].exp << " |\n";


					setCursorPosition(chord.x - 56, 8 + chord.y / 8 + 8 + 10 * counter);
					cout << "|_________________|__________________________________|\n";
					counter++;
				}

			}
		}

		setlocale(LC_ALL, "en_US.UTF-8");
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		if (num != 0)
		{
			setCursorPosition(3, chord.y - 2);
			cout << u8"░░██╗";
			setCursorPosition(3, chord.y - 1);
			cout << u8"░██╔╝";
			setCursorPosition(3, chord.y);
			cout << u8"██╔╝░";
			setCursorPosition(3, chord.y + 1);
			cout << u8"╚██╗░";
			setCursorPosition(3, chord.y + 2);
			cout << u8"░╚██╗";
			setCursorPosition(3, chord.y + 3);
			cout << u8"░░╚═╝";
		}
		if (num != sizeProductBase / 5)
		{
			setCursorPosition(chord.x * 1.6, chord.y - 2);
			cout << u8"██╗░░";
			setCursorPosition(chord.x * 1.6, chord.y - 1);
			cout << u8"╚██╗░";
			setCursorPosition(chord.x * 1.6, chord.y);
			cout << u8"░╚██╗";
			setCursorPosition(chord.x * 1.6, chord.y + 1);
			cout << u8"░██╔╝";
			setCursorPosition(chord.x * 1.6, chord.y + 2);
			cout << u8"██╔╝░";
			setCursorPosition(chord.x * 1.6, chord.y + 3);
			cout << u8"╚═╝░░";
		}
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		int a = _getch();
		if (a == 75) {
			num--;
			if (num < 0)num++;
		}
		else if (a == 77) {
			num++;
			//if (num > (sizeProductBase+4)/5 -1)num--;
			if (num * 5 > sizeProductBase)num--;
		}
		else if (a == 27)
		{
			system("cls");
			setting = readSettingsFile();
			break;
		}
		else if (a >= 48 && a <= 57)
		{
			line = line + static_cast<char>(a);
			cout << static_cast<char>(a);
		}
		else if (a == 8 && line != "")
		{
			line.pop_back();
			setCursorPosition(chord.x - 56 + line.size(), 3 + chord.y / 4 + 17);
			cout << " ";
		}
		else if (a == 13 && line != "")
		{
			if(stoi(line)>=0 && stoi(line)<=sizeProductBase)
			thisProduct2(stoi(line));	
		}
		else if (a == 33)
		{	
			newJob(sizeProductBase+1);
		}
	}
}
void thisProduct2(int num)
{
	int tapp = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;
	const int sizeBase = 8;

	string allname[sizeBase] = { "Тип занятости:   " ,"Спеиальность:    " ,"Опыт:            " ,"Время от:        ","Время до:        ","Адрес:           " ,"Зарплата:        " ,"Номер для связи: " };
	string allFunc[sizeBase] = { product[num].type ,product[num].profession,product[num].exp,product[num].from,product[num].to ,product[num].adress, product[num].salary, product[num].contacts };

	system("cls");

	string setting2_Base[sizeBase] = { "!. Удалить", "%. Назад" };
	for (int i = 0; i < sizeBase; i++) maxSize = max(setting2_Base[i].size(), maxSize);
	for (int i = 0; i < 2; i++)
	{
		SetConsoleTextAttribute(hC, lastColor);
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 5 + i * 3 + 2);
		cout << setting2_Base[i];
	}

	for (int i = 0; i < sizeBase; i++)
	{
		SetConsoleTextAttribute(hC, lastColor);
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + i * 3);
		cout << allname[i]<<" "<< allFunc[i];
	}


	nameController(product[num].name);
	while (1)
	{
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2-3, 3 + chord.y / 3 + lastCursore *3);
		SetConsoleTextAttribute(hC, lastColor);
		cout << "   " << allname[lastCursore]<<" " << allFunc[lastCursore];

		setCursorPosition(chord.x / 5 + 28 + maxSize + 2-3, 3 + chord.y / 3 + cursoreLine *3);
		SetConsoleTextAttribute(hC, activeColor);
		cout << ">> " << allname[cursoreLine] <<" " << allFunc[cursoreLine];

		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 + allFunc[cursoreLine].size() , 3 + chord.y / 3 + cursoreLine * 3);

		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(sizeBase, cursoreLine, tapp);
		}
		else if (tapp == 8 && allFunc[cursoreLine] !="")
		{
			allFunc[cursoreLine].pop_back();
			setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + cursoreLine * 3);
			cout << "                                                           ";
			setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + cursoreLine * 3 );
			cout << ">> " << allname[cursoreLine] << " " << allFunc[cursoreLine];

		}
		else if (tapp == 27 || (cursoreLine == 1 && tapp == 13))
		{
			system("cls");
			break;
		}
		else if (((tapp >= 65 && tapp <= 122) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46))
		{

			allFunc[cursoreLine] = allFunc[cursoreLine] + static_cast<char>(tapp);
			cout << static_cast<char>(tapp);
		}
		else if (tapp == 37)
		{
			product[num].type = allFunc[0];
			product[num].profession = allFunc[1];
			product[num].exp = allFunc[2];
			product[num].from = allFunc[3];
			product[num].to = allFunc[4];
			product[num].adress = allFunc[5];
			product[num].salary = allFunc[6];
			product[num].contacts = allFunc[7];

			ofstream rite("Users/" + userSetting[userInSystem].login2 + ".txt");
			for (int i = 0; i < sizeProductBase; i++)
			{
				rite << product[i].getall() << endl;
			}
			rite.close();
		}
		else if (tapp == 33)
		{
			ofstream rite("Users/" + userSetting[userInSystem].login2 + ".txt");
			for (int i = 0; i < sizeProductBase; i++)
			{
				if (i != num)rite << product[i].getall()<<endl;
			}
			break;
		}
	}
}

void newJob(int num)
{
	int tapp = 0;
	int lastCursore = 0;
	int cursoreLine = 0;
	int maxSize = 0;
	const int sizeBase = 9;

	string allname[sizeBase] = { "Название:            ","Тип занятости:   " ,"Спеиальность:    " ,"Опыт:            " ,"Время от:        ","Время до:        ","Адрес:           " ,"Зарплата:        " ,"Номер для связи: " };
	string allFunc[sizeBase] = {"","","","","","","",""};

	system("cls");

	string setting2_Base[sizeBase] = { "esc. Назад", "%. Сохранить" };
	for (int i = 0; i < sizeBase; i++) maxSize = max(setting2_Base[i].size(), maxSize);
	for (int i = 0; i < 2; i++)
	{
		SetConsoleTextAttribute(hC, lastColor);
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 5);
		cout << setting2_Base[i];
	}

	for (int i = 0; i < sizeBase; i++)
	{
		SetConsoleTextAttribute(hC, lastColor);
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2, 3 + chord.y / 3 + i * 3 + 5);
		cout << allname[i] << " " << allFunc[i];
	}


	nameController(product[num].name);
	while (1)
	{
		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + lastCursore * 3 +5);
		SetConsoleTextAttribute(hC, lastColor);
		cout << "   " << allname[lastCursore] << " " << allFunc[lastCursore];

		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + cursoreLine * 3 +5);
		SetConsoleTextAttribute(hC, activeColor);
		cout << ">> " << allname[cursoreLine] << " " << allFunc[cursoreLine];

		setCursorPosition(chord.x / 5 + 28 + maxSize + 2 + allFunc[cursoreLine].size(), 3 + chord.y / 3 + cursoreLine * 3+5);

		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(sizeBase, cursoreLine, tapp);
		}
		else if (tapp == 8 && allFunc[cursoreLine] != "")
		{
			allFunc[cursoreLine].pop_back();
			setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + cursoreLine * 3 + 5);
			cout << "                                                           ";
			setCursorPosition(chord.x / 5 + 28 + maxSize + 2 - 3, 3 + chord.y / 3 + cursoreLine * 3 + 5);
			cout << ">> " << allname[cursoreLine] << " " << allFunc[cursoreLine];
		}
		else if (((tapp >= 65 && tapp <= 122) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46))
		{

			allFunc[cursoreLine] = allFunc[cursoreLine] + static_cast<char>(tapp);
			cout << static_cast<char>(tapp);
		}
		else if (tapp == 27) break;
		else if (tapp == 37)
		{
			product[num].name = allFunc[0];
			product[num].type = allFunc[1];
			product[num].profession = allFunc[2];
			product[num].exp = allFunc[3];
			product[num].from = allFunc[4];
			product[num].to = allFunc[5];
			product[num].adress = allFunc[6];
			product[num].salary = allFunc[7];
			product[num].contacts = allFunc[8];
			product[num].login = userSetting[userInSystem].login2;
			product[num].setAll(product[num]);
			string text = product[num].getall();
			ofstream rite("Users/" + userSetting[userInSystem].login2 + ".txt", ios::app);
			rite << text << endl;
			rite.close();

			readProductBase();
			ofstream rate("Data/products.txt", ios::app);
			rate << text << endl;
		}
	}
}
void myCab(int t)
{
	system("cls");

	const int interface1Size = 8;
	int interface1Size2 = 0;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;
	int numRole = 0;

	string buttons[2] = { "1. Редактировать","2. Назад" };
	string settingsInterface1[interface1Size] = { "Логин:         ", "Пароль:        ","Код доступа:   ", "Роль:          "
		, "Возраст:       ","Специализация: ",  "Пол:           " , "Тема анкеты: "};
	string settingsInterface2[interface1Size] = { userSetting[userInSystem].login2, userSetting[userInSystem].password2, 
		userSetting[userInSystem].codeIn2,userSetting[userInSystem].role2
		,userSetting[userInSystem].age2,userSetting[userInSystem].specialization2,userSetting[userInSystem].sex2,userSetting[userInSystem].theme2};
	string newSettings[5];
	string nameNewSetting;
	for (int i = 0; i < 5; i++)newSettings[i] = userSetting[userInSystem].personalChar2[i];
	string sexMass[2] = { "М","Ж" };

	nameController(userSetting[userInSystem].login2);


	for (int i = 0; i < interface1Size; i++)maxSize = max(buttons[i].size(), maxSize);

	for (int i = 0; i < 2; i++) {
		setCursorPosition(22, 33 + 2 * i);
		cout << "                                 ";
		setCursorPosition(22, 33+2*i);
		cout << buttons[i];
	}

	setCursorPosition(22, 15);
	cout << settingsInterface1[0] << settingsInterface2[0];
	setCursorPosition(22, 17);
	cout << settingsInterface1[1] << settingsInterface2[1];
	setCursorPosition(22, 19);
	cout << settingsInterface1[2] << settingsInterface2[2];
	setCursorPosition(22, 21);
	cout << settingsInterface1[3] << settingsInterface2[3];
	setCursorPosition(22, 23);
	cout << settingsInterface1[4] << settingsInterface2[4];
	setCursorPosition(22, 25);
	cout << settingsInterface1[5] << settingsInterface2[5];
	setCursorPosition(22, 27);
	cout << settingsInterface1[6] << settingsInterface2[6];
	setCursorPosition(22, 29);
	cout << settingsInterface1[7] << settingsInterface2[7];


	setCursorPosition(73, 19);
	cout << "Персональные характеристики:";
	for (int i = 0; i < 5; i++) {
		setCursorPosition(75, 21+2*i);
		cout << newSettings[i];
	}


	while (1)
	{
		SetConsoleTextAttribute(hC, activeColor);

		setCursorPosition(22-3, 33 + 2 * lastCursore);
		cout << "   " << buttons[lastCursore];


		setCursorPosition(22-3, 33 + 2 * cursoreLine);
		cout << ">> ";
		cout << buttons[cursoreLine];


		tapp = _getch();


		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(2, cursoreLine, tapp);
		}
		else if (tapp == 27 || tapp == 2 || (cursoreLine == 1 && tapp == 13))
		{
			system("cls");
			break;
		}
	}
}
void myCab_Continuation()
{
	const int interface1Size = 6;
	int maxSize = 0;
	int cursoreLine = 0;
	int lastCursore = 0;
	int tapp;

	string settingsInterface1[interface1Size] = { "1. ", "2. ","3. ","4. ", "5. " , "Подтвердить"};
	string newSettings[interface1Size] = { "","","","",""};
	for (int i = 0; i < interface1Size - 1; i++) newSettings[i] = userSetting[userInSystem].customizableChar[i];

	for (int i = 0; i < interface1Size; i++)maxSize = max(settingsInterface1[i].size(), maxSize);

	for (int i = 0; i < interface1Size; i++) {
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << "                                 ";
		setCursorPosition(chord.x - maxSize - 22, 3 + chord.y / 4 + i * 3 + 8);
		cout << settingsInterface1[i] << newSettings[i];
	}

	while (1)
	{

		SetConsoleTextAttribute(hC, activeColor);

		if (cursoreLine != interface1Size - 1)ShowConsoleCursor(1);
		else ShowConsoleCursor(0);

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + lastCursore * 3 + 8);
		cout << "   " << settingsInterface1[lastCursore];

		setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + cursoreLine * 3 + 8);
		cout << ">> ";
		cout << settingsInterface1[cursoreLine];

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);
		tapp = _getch();

		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length() - 5, 3 + chord.y / 4 + 4 * 3 + 8);
		cout << "                                                 ";
		setCursorPosition(chord.x - 20 + newSettings[cursoreLine].length(), 3 + chord.y / 4 + cursoreLine * 3 + 8);


		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if (((tapp >= 65 && tapp <= 122 && cursoreLine != interface1Size - 1) || (tapp >= 48 && tapp <= 57) || tapp == 64 || tapp == 46) && cursoreLine != interface1Size - 1)
		{
			newSettings[cursoreLine] = newSettings[cursoreLine] + static_cast<char>(tapp);
			cout << static_cast<char>(tapp);
		}
		else if (tapp == 8 && newSettings[cursoreLine] != "" && cursoreLine != 5)
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
			for (int i = 0; i < interface1Size - 1; i++) userSetting[userInSystem].customizableChar[i] = newSettings[i];
		}
		else if (tapp == 27)
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x / 2, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                                                                        ";
			}
			break;
		}
	}
}

void adminMenu()
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

	string settingsInterface1[interface1Size] = { "1. Работа","2. Мои места","3. Личный кабинет", "4. Выход" };

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


		setCursorPosition(chord.x / 4 + (maxSize + 3), 3 + chord.y / 4 + cursoreLine * 3);
		tapp = _getch();

		if (tapp == 80 || tapp == 72)
		{
			lastCursore = cursoreLine;
			cursoreLine = gotoThisLine(interface1Size, cursoreLine, tapp);
		}
		else if (tapp == 27 || tapp == 52 || (cursoreLine == interface1Size - 1 && tapp == 13))
		{
			ShowConsoleCursor(0);
			SetConsoleTextAttribute(hC, lastColor);

			for (int i = 0; i < interface1Size + 1; i++) {
				setCursorPosition(chord.x - maxSize - 25, 3 + chord.y / 4 + i * 3 + 8);
				cout << "                                                ";
			}
			break;
		}
		else if (tapp == 13)
		{
			if (cursoreLine == 0) { entrance(); }
			if (cursoreLine == 1) { reg(); }
			if (cursoreLine == 2) { inf(); }
		}
		else if (tapp == 49)entrance();
		else if (tapp == 50)reg();
		else if (tapp == 51)inf();

	}
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
	sizeUserSettings = 0;

	while (!read2.eof())
	{
		read2 >> theme2 >> login2 >> password2 >> codeIn2 >> role2 >> age2 >> specialization2 >> sex2
			>> personalChar2[0] >> personalChar2[1] >> personalChar2[2] >> personalChar2[3]
			>> customizableChar[0] >> customizableChar[1] >> customizableChar[2] >> customizableChar[3] >> customizableChar[4]
			>> card;

		userSetting[sizeUserSettings].setAll(theme2, login2, password2, codeIn2, role2, age2, specialization2, sex2, personalChar2, customizableChar, card);
		sizeUserSettings++;
	}
	sizeUserSettings--;
}
void readProductBase()
{
	ofstream read1("Data/products.txt", ios::app);
	read1.close();

	ifstream read2("Data/products.txt");
	string from;
	string to;
	string adress;
	string salary;
	string type;
	string exp;
	string login;
	string name;

	string profession;
	string contacts;

	sizeProductBase = 0;
	while (!read2.eof())
	{
		read2 >> name >> from >> to >> adress >> salary >> type >> exp >> login >> profession >> contacts;
		product[sizeProductBase].setAll(name, from, to, adress, salary, type, exp, login, profession, contacts);
		sizeProductBase++;
	}
	sizeProductBase--;
}
void readProductBase(string line)
{
	ofstream read1("Users/"+ line +".txt", ios::app);
	read1.close();

	ifstream read2("Users/" + line + ".txt");
	string from;
	string to;
	string adress;
	string salary;
	string type;
	string exp;
	string login;
	string name;

	string profession;
	string contacts;

	sizeProductBase = 0;
	while (!read2.eof())
	{
		read2 >> name >> from >> to >> adress >> salary >> type >> exp >> login >> profession >> contacts;
		product[sizeProductBase].setAll(name, from, to, adress, salary, type, exp, login, profession, contacts);
		sizeProductBase++;
	}
	sizeProductBase--;
}

