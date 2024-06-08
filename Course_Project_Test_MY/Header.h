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
using namespace std;

//--------------------------структуры--------------------------//
struct CHORDS
{
	int x;
	int y;
};
//--------------------------basic settings--------------------------//
//----------workFunctions.cpp----------//
void basikSettings();
void draw();
static void UnwrapScreen();
void setCursorPosition(int x, int y);
void writeBorder();
CHORDS getConsleChords();
int gotoThisLine(int maxSize, int positionCursore, int tapp);


//--------------------------read settings--------------------------//
bool readSettings(string way);
void masterOfSettings();
void settingMenu_1();



#endif