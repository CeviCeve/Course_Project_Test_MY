#ifndef DEBUG


#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <cctype>
#include <iomanip>
#include <codecvt>
#include <regex>
using namespace std;

//--------------------------структуры--------------------------//
struct CHORDS
{
	int x;
	int y;
};
struct SETTINGS
{
	string title;
	string email;
	string corporationPassword;
	void setAllPartOne(string title, string email, string corporationPassword)
	{
		this->title = title;
		this->email = email;
		this->corporationPassword = corporationPassword;
	}

	bool correctTheme=0;
	bool correctDB = 0;
	bool correctCab = 0;
	bool temporaryPassord = 0;
	void setAllAdminFunc(bool theme, bool correctDB, bool correctCab, bool temporaryPassord)
	{
		this->correctTheme = theme;
		this->correctDB = correctDB;
		this->correctCab = correctCab;
		this->temporaryPassord = temporaryPassord;

	}


	string theme;
	bool profileCorrect = 0;
	void setBaseFunc1(string theme, bool profileCorrect)
	{
		this->theme = theme;
		this->profileCorrect = profileCorrect;
	}


	bool login = 0;
	bool password = 0;
	bool codeIn = 0;
	void setAuthFunc1(bool login, bool password, bool codeIn)
	{
		this->login = login;
		this->password = password;
		this->codeIn = codeIn;
	}

	bool role = 0;
	bool age = 0;
	bool specialization = 0;
	bool sex = 0;
	string personalChar[4] = { "","","","" };
	void setUserCard1(bool role, bool age, bool specialization, bool sex)
	{
		this->role = role;
		this->age = age;
		this->specialization = specialization;
		this->sex = sex;
	}

	int sizeCustomizable;
	string customizableChar[5];
	void setCustomizable(string mass[], int sizeMass)
	{
		sizeCustomizable = sizeMass;
		for (int i = 0; i < sizeMass; i++) customizableChar[i] = mass[i];
	}
	string getCustom()
	{
		string a ="";
		for (int i = 0; i < 5; i++)
		{
			a += customizableChar[i] + " ";
			if (customizableChar[i] != "") sizeCustomizable = i;
		}
		a += to_string(sizeCustomizable+1);
		return a;
	}
};
struct USER_SETTINGS
{
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

	void setAll(string theme2,string login2,string password2,string codeIn2,string role2,string age2,string specialization2,string sex2,string personalChar2[],	string customizableChar[],	int card)
	{
		this->theme2 = theme2;
		this->login2 = login2;
		this->password2 = password2;
		this->codeIn2 = codeIn2;
		this->role2 = role2;
		this->age2 = age2;
		this->specialization2 = specialization2;
		this->sex2 = sex2;
		for (int i = 0; i < 4; i++)this->personalChar2[i] = personalChar2[i];
		for (int i = 0; i < 5; i++)this->customizableChar[i] = customizableChar[i];
		this->card;
	}

	void setAll(USER_SETTINGS user_settings)
	{
		this->theme2 = user_settings.theme2;
		this->login2 = user_settings.login2;
		this->password2 = user_settings.password2;
		this->codeIn2 = user_settings.codeIn2;
		this->role2 = user_settings.role2;
		this->age2 = user_settings.age2;
		this->specialization2 = user_settings.specialization2;
		this->sex2 = user_settings.sex2;
		for (int i = 0; i < 4; i++)this->personalChar2[i] = user_settings.personalChar2[i];
		for (int i = 0; i < 5; i++)this->customizableChar[i] =user_settings.customizableChar[i];
		this->card= user_settings.card;
	}

	string retStr()
	{
		string line = "";
		for (int i = 0; i < 4; i++)
		{
			if (personalChar2[i] == "")personalChar2[i] = "0";
			line += personalChar2[i] + " ";
		}
		for (int i = 0; i < 5; i++)
		{
			if (customizableChar[i] == "")customizableChar[i] = "0";
			line += customizableChar[i] + " ";
		}
		return line;

	}

	string getAll()
	{
		return theme2 + " " + login2 + " "  + password2 + " " + codeIn2 + " " + role2 + " " + age2 + " " + specialization2 + " " + sex2
			+ " " + retStr() + to_string(card);
	}
};
struct PRODUCT
{
	string name;
	string from;
	string to;
	string adress;
	string salary;
	string type;
	string exp;

	string login;
	string profession;
	string contacts;

	void setAll(string name,string from, string to, string adress, string salary, string type, string exp, string login, string professional, string contacts)
	{
		this->name = name;
		this->from = from;
		this->to = to;
		this->adress = adress;
		this->salary = salary;
		this->type = type;
		this->exp = exp;
		this->login = login;
		this->profession = professional;
		this->contacts = contacts;
	}

	void setAll(PRODUCT product)
	{
		this->name = product.name;
		this->from = product.from;
		this->to = product.to;
		this->adress = product.adress;
		this->salary = product.salary;
		this->type = product.type;
		this->exp = product.exp;
		this->login = product.login;
		this->profession = product.profession;
		this->contacts = product.contacts;
	}

	string getall()
	{
		return name + " " + from + " " + to + " " + adress + " " + salary + " " + type + " " + exp + " " + login + " " + profession + " " + contacts;
	}
};
struct LINK
{
	string nameMy;
	string nameHim;
	string nameProduct;

	void setAll(string nameHim, string nameMy, string nameProduct)
	{
		this->nameMy = nameMy;
		this->nameHim = nameHim;
		this->nameProduct = nameProduct;
	}
	string getAll()
	{
		return nameHim + " " + nameMy + " " + nameProduct;
	}
};
//--------------------------basic settings--------------------------//
//----------workFunctions.cpp----------//
void basikSettings();
bool isValidEmail(const std::string& email);
void setCursorPosition(int x, int y);
static void UnwrapScreen();
CHORDS getConsleChords();
void ShowConsoleCursor(bool showFlag);
string generateRandomString(int size);
string inOneLine(string str);
bool isNumber(const string& str);

void draw();
void writeBorder();
int gotoThisLine(int maxSize, int positionCursore, int tapp);
void leave();


//--------------------------read settings--------------------------//
bool readSettings(string way);
SETTINGS readSettingsFile();
void masterOfSettings();
void startMasterDraw();
void settingMenu_1();
void settingMenu_2();

void drawObjects(int tapp);
void drawAdmin(int code);
void deleteZone(int maxSizeX);

void drawBase(int code);
void drawAutor(int code);
void drawTempl(int code);
void drawRole(int code);
void completeSetting();

void readUserBase();
void readProductBase();
void readProductBase(string name);
//--------------------------- main menu ---------------------------//
void newSettings();
//---------------------------objects-----------------------------//
void printUserCardController(int numCardStyle, SETTINGS settings, USER_SETTINGS userSettings, int color, int X);
void userCard1(string name[], string name2[], string thisData[], int maxsize, int color, int X);
void userCard2(string name[], string name2[], string thisData[], int maxsize, int color, int X);
void userCard3(string name[], string name2[], string thisData[], int maxsize, int color, int X);
void nameController(string name);
void a(int space);
//---------------------------myApp--------------------------//
void myApp();
void entrance();
void reg();
void reg2();
void inf();

void adminMenu();
void delUsers();

void userMenu();
void myCab(int num);
void myCab_Continuation();
void myJob(int num);
void job(int num);
void thisProduct(int num);
void thisProduct2(int num);
void newJob(int num);
void settings1(int code);
void settings2(int code);
void myCab_part1();
void myCard(int num);

#endif