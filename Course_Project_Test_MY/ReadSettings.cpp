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

SETTINGS readSettingsFile()
{
	SETTINGS all;
	ifstream read("Settings/app.txt");

	read >> all.title >> all.email >> all.corporationPassword >> all.theme
		>> all.customizableChar[0] >> all.customizableChar[1]
		>> all.customizableChar[2] >> all.customizableChar[3] >> all.customizableChar[4]
		>> all.sizeCustomizable;
	read.close();


	ifstream read2("Settings/user.txt");

	read2>>all.profileCorrect>>all.login>>all.password>>all.codeIn
		>>all.role>>all.age>>all.specialization>>all.sex;
	read2.close();


	ifstream read3("Settings/admin.txt");

	read3 >> all.correctTheme >> all.correctDB >> all.correctCab >> all.temporaryPassord;
	read3.close();

	return all;
}