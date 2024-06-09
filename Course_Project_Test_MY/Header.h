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
void drawAdmin();
void deleteZone(int maxSizeX);

void drawBase();
void drawAutor();
void drawTempl();
void drawRole();


#endif