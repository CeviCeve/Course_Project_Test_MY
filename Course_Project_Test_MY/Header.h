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

};

struct newSETTINGS_ALL
{
	string name;
	string email;
	string password;
	string theme;

	string newCharacteristics[5];
	int sizeChar;
};
//--------------------------basic settings--------------------------//
//----------workFunctions.cpp----------//
void basikSettings();
bool isValidEmail(const std::string& email);
void setCursorPosition(int x, int y);
static void UnwrapScreen();
CHORDS getConsleChords();
void ShowConsoleCursor(bool showFlag);


void draw();
void writeBorder();
int gotoThisLine(int maxSize, int positionCursore, int tapp);
void leave();


//--------------------------read settings--------------------------//
bool readSettings(string way);
newSETTINGS_ALL readSettingsFile();
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

//--------------------------- main menu ---------------------------//
void newSettings();
//---------------------------objects-----------------------------//
void printUserCardController(int numCardStyle, SETTINGS settings, USER_SETTINGS userSettings);
void userCard1(string name[], string name2[], string thisData[], string thisData2[], int maxsize);
void userCard2(string name[], string name2[], string thisData[], string thisData2[], int maxsize);
void userCard3(string name[], string name2[], string thisData[], string thisData2[], int maxsize);

void nameController(string name);
void a(int space);
//---------------------------myApp--------------------------//
void myApp();
void entrance();
void reg();
void inf();

#endif