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

//--------------------------basic settings--------------------------//
//----------workFunctions.cpp----------//
void basikSettings();
static void UnwrapScreen();
void setCursorPosition(int x, int y);
void writeBorder();
void getConsleChords();

//--------------------------read settings--------------------------//
bool readSettings(string way);
void masterOfSettings();

class Function
{
public:
	int a;
};


#endif