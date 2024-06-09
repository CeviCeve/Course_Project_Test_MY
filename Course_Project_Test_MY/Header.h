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

	bool correctTheme;
	bool correctDB;
	bool correctCab;
	bool temporaryPassord;

	void setAllAdminFunc(bool theme, bool correctDB, bool correctCab, bool temporaryPassord)
	{
		this->correctTheme = theme;
		this->correctDB = correctDB;
		this->correctCab = correctCab;
		this->temporaryPassord = temporaryPassord;

	}

	string theme;
	bool profileCorrect;

	void setBaseFunc1(string theme, bool profileCorrect)
	{
		this->theme = theme;
		this->profileCorrect = profileCorrect;
	}

	bool login;
	bool password;
	bool codeIn;

	void setAuthFunc1(bool login, bool password, bool codeIn)
	{
		this->login = login;
		this->password = password;
		this->codeIn = codeIn;
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


void draw();
void writeBorder();
int gotoThisLine(int maxSize, int positionCursore, int tapp);
void leave();



//--------------------------read settings--------------------------//
bool readSettings(string way);
void masterOfSettings();
void startMasterDraw();
void settingMenu_1();
void settingMenu_2();

void drawObjects(int tapp);
void drawAdmin(int code);
void deleteZone(int maxSizeX);

void drawBase(int code);
void drawAutor(int code);
void drawTempl();
void drawRole();


#endif