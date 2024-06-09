#include "Header.h"

HANDLE honsole = GetStdHandle(STD_OUTPUT_HANDLE);

void printUserCardController(int numCardStyle, SETTINGS settings, USER_SETTINGS userSettings)
{
	string thisData[4] = { "","","","" };
	string name[4] = { "","","","" };
	int ch = 0;
	if (settings.role) { thisData[ch] = settings.personalChar[0]; name[ch] = "Роль:    "; ch++; }
	if (settings.age) { thisData[ch] = settings.personalChar[1]; name[ch] = "Возраст: "; ch++; }
	if (settings.specialization) { thisData[ch] = settings.personalChar[2]; name[ch] = "Профиль: "; ch++; }
	if (settings.sex) { thisData[ch] = settings.personalChar[3]; name[ch] = "Пол:     "; ch++; }
	for (int i = 0; i < 4; i++) if (name[i] == "") name[i] = "         ";

	string thisData2[7] = { "","","","","","","" };
	string name2[7] = { "","","","","","","" };
	int maxsize = 0;
	int ch2 = 0;
	for (int i = 0; i < 7; i++)
	{
		maxsize = max(maxsize, name2[i].size());
		if (settings.customizableChar[i] != "")
		{
			thisData2[ch2] = settings.customizableChar[i] + ":";
			name2[ch2] = userSettings.customizableChar[i];
			ch2++;
		}
	}

	if (numCardStyle == 1)userCard1(name, name2, thisData, thisData2, maxsize);
	if (numCardStyle == 1)userCard2(name, name2, thisData, thisData2, maxsize);
	if (numCardStyle == 1)userCard3(name, name2, thisData, thisData2, maxsize);

}

void userCard1(string name[], string name2[], string thisData[], string thisData2[], int maxsize)
{

	cout << "[================т----------------------------------------------]\n"
		<< "|    ________    | " << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize) << thisData2[0] << " " << name2[0] << endl
		<< "|   /        \\   | " << "                         | " << setw(maxsize) << thisData2[1] << " " << name2[1] << endl
		<< "|  |          |  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize) << thisData2[2] << " " << name2[2] << endl
		<< "|  |          |  | " << "                         | " << setw(maxsize) << thisData2[3] << " " << name2[3] << endl
		<< "|   \\        /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << thisData2[4] << " " << name2[4] << endl
		<< "|   /\\______/\\   | " << "                         | " << setw(maxsize) << thisData2[5] << " " << name2[5] << endl
		<< "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << setw(maxsize) << thisData2[6] << " " << name2[6] << endl
		<< "[================L----------------------------------------------]";
}
void userCard2(string name[], string name2[], string thisData[], string thisData2[], int maxsize)
{
SetConsoleTextAttribute(honsole, 14);
	cout << "[================т-----------------------------------------------]\n"
		<< "|    ________    | "   << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize) << thisData2[0] << " " << name2[0] << endl
		<< "|   / ___  __\\   | "                 <<"                         | " << setw(maxsize) << thisData2[1] << " " << name2[1] <<endl
		<< "|  |_/"; SetConsoleTextAttribute(honsole, 51); cout << "   "; SetConsoleTextAttribute(honsole, 14); cout << "=="; SetConsoleTextAttribute(honsole, 51); cout << "   "; SetConsoleTextAttribute(honsole, 14); 
	cout << "|  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize) << thisData2[2] << " " << name2[2] << endl
		<< "|  |          |  | " << "                         | " << setw(maxsize) << thisData2[3] << " " << name2[3] << endl
		<< "|   \\        /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << thisData2[4] << " " << name2[4] << endl
		<< "|   /\\______/\\   | " << "                         | " << setw(maxsize) << thisData2[5] << " " << name2[5] << endl
		<< "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << setw(maxsize) << thisData2[6] << " " << name2[6] << endl
		<< "[================L----------------------------------------------]";
}
void userCard3(string name[], string name2[], string thisData[], string thisData2[], int maxsize)
{
	SetConsoleTextAttribute(honsole, 14);
	cout << "[================т-----------------------------------------------]\n"
		<< "|    ________    | " << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize) << thisData2[0] << " " << name2[0] << endl
		<< "|   / ___  __\\   | " << "                         | " << setw(maxsize) << thisData2[1] << " " << name2[1] << endl
		<< "|  |          |  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize) << thisData2[2] << " " << name2[2] << endl
		<< "|  |   /____\\ |  | " << "                         | " << setw(maxsize) << thisData2[3] << " " << name2[3] << endl
		<< "|   \\   ____ /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << thisData2[4] << " " << name2[4] << endl
		<< "|   /\\______/\\   | " << "                         | " << setw(maxsize) << thisData2[5] << " " << name2[5] << endl
		<< "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << setw(maxsize) << thisData2[6] << " " << name2[6] << endl
		<< "[================L----------------------------------------------]";
}

