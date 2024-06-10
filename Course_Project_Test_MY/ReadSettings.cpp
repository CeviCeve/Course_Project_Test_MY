#include "Header.h"

bool readSettings(string way)
{
	string a;

	ofstream createSettingsFile(way, ios::app);
	createSettingsFile.close();

	ifstream openSettingsFile(way);
	openSettingsFile >> a;

	if (a == "" || a == "0") { return 0; }
	else { return 1; }
}

newSETTINGS_ALL readSettingsFile()
{
	newSETTINGS_ALL all;
	ifstream read("Settings/app.txt");

	read >> all.name >> all.email >> all.password >> all.theme
		>> all.newCharacteristics[0] >> all.newCharacteristics[1]
		>> all.newCharacteristics[2] >> all.newCharacteristics[3] >> all.newCharacteristics[4]
		>> all.sizeChar;

	read.close();

	return all;
}