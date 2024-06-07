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