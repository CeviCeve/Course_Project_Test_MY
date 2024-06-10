#include "Header.h"

HANDLE honsole = GetStdHandle(STD_OUTPUT_HANDLE);
string letters[26];
CHORDS hords = getConsleChords();

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
	if (numCardStyle == 2)userCard2(name, name2, thisData, thisData2, maxsize);
	if (numCardStyle == 3)userCard3(name, name2, thisData, thisData2, maxsize);

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



void nameController(string name)
{
	string abc = "abcdefghijklmnopqrstuvwxyz";
	string abcB = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = name.size(); i >= 0; i--)
	{
		setCursorPosition(hords.x - name.size() * 6 + i * 7, 5);
		a(hords.x - name.size() * 6 + i * 7 - 7);
		for (int y = 0; y < 26; y++)
		{
			if (abc[y] == name[i] || abcB[y] == name[i])
			{
				cout << letters[y];
				break;
			}
		}
	}
}

void a(int space)
{

	string space1 = "";
	for (int i = 0; i < space+7; i++)space1 += " ";
	letters[0] =
			" ___ \n"
	+space1+"|   |\n"
	+ space1 + "|___|\n"
	+ space1 + "|   |\n"
	+ space1 + "|   |";


	letters[1] =
		" ___ \n"
		+ space1 + "|   \\\n"
		+ space1 + "|___/\n"
		+ space1 + "|    \\\n"
		+ space1 + "L____/";

	letters[2] =
		" ____\n"
		+ space1 + "/    \n"
		+ space1 + "|    \n"
		+ space1 + "|   \n"
		+ space1 + "\\____\n";

	letters[3] =
		" ____\n"
		+ space1 + "|    \\\n"
		+ space1 + "|    |\n"
		+ space1 + "|    /\n"
		+ space1 + "L___/";

	letters[4] =
		" ____\n"
		+ space1 + "|    \n"
		+ space1 + "|____\n"
		+ space1 + "|    \n"
		+ space1 + "|____\n";

	letters[5] =
		" ____\n"
		+ space1 + "|    \n"
		+ space1 + "|___ \n"
		+ space1 + "|    \n"
		+ space1 + "|    ";

	letters[6] =
		" ____\n"
		+ space1 + "/    \n"
		+ space1 + "|  __\n"
		+ space1 + "|   |\n"
		+ space1 + "\\___/\n";

	letters[7] =
		"|    \n"
		+ space1 + "|    \n"
		+ space1 + "|___ \n"
		+ space1 + "|   \\\n"
		+ space1 + "|   |";

	letters[8] =
		"_____\n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n"
		+ space1 + "_____\n";

	letters[9] =
		"__   \n"
		+ space1 + "|    \n"
		+ space1 + "|  __\n"
		+ space1 + "|   |\n"
		+ space1 + "\\___/\n";

	letters[10] =
		"|  / \n"
		+ space1 + "| /  \n"
		+ space1 + "|/   \n"
		+ space1 + "| \\ \n"
		+ space1 + "|  \\\n";

	letters[11] =
		"|    \n"
		+ space1 + "|    \n"
		+ space1 + "|    \n"
		+ space1 + "|    \n"
		+ space1 + "|___|";

	letters[12] =
		"|\\  /|\n"
		+ space1 + "| \\/ |\n"
		+ space1 + "|    |\n"
		+ space1 + "|    |\n"
		+ space1 + "|    |";

	letters[13] =
		"|   |\n"
		+ space1 + "|\\  |\n"
		+ space1 + "| \\ |\n"
		+ space1 + "|  \\|\n"
		+ space1 + "|   |";

	letters[14] =
		" ___ \n"
		+ space1 + "/   \\\n"
		+ space1 + "|   |\n"
		+ space1 + "|   |\n"
		+ space1 + "\\___/";

	letters[15] =
		" ___ \n"
		+ space1 + "|   \\\n"
		+ space1 + "|___/\n"
		+ space1 + "|    \n"
		+ space1 + "|    ";

	letters[16] = 
		" ___ \n"
		+ space1 + "/   \\\n"
		+ space1 + "\\___/\n"
		+ space1 + "   / \n"
		+ space1 + "  |_/";

	letters[17] =
		" ___ \n"
		+ space1 + "|   |\n"
		+ space1 + "|___/\n"
		+ space1 + "|  \\\n"
		+ space1 + "|   \\";

	letters[18] =
		" ___ \n"
		+ space1 + "/    \n"
		+ space1 + "\\___ \n"
		+ space1 + "    \\\n"
		+ space1 + " ___/";

	letters[19] =
		"_____\n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n";

	letters[20] =
		"|   |\n"
		+ space1 + "|   |\n"
		+ space1 + "|   |\n"
		+ space1 + "|   |\n"
		+ space1 + "\\___/";

	letters[21] = 
		"     \n"
		+ space1 + "|   |\n"
		+ space1 + "\\   /\n"
		+ space1 + " \\ /\n"
		+ space1 + "  V";

	letters[22] =
		"     \n"
		+ space1 + "| | |\n"
		+ space1 + "\\ | /\n"
		+ space1 + " \\|/\n"
		+ space1 + "  V";

	letters[23] =
		"\\   /\n"
		+ space1 + " \\ / \n"
		+ space1 + "  X  \n"
		+ space1 + " / \\\n"
		+ space1 + "/   \\";

	letters[24] =
		"|   |\n"
		+ space1 + " \\ / \n"
		+ space1 + "  |  \n"
		+ space1 + "  |  \n"
		+ space1 + "  |  ";

	letters[25] =
		"_____\n"
		+ space1 + "    /\n"
		+ space1 + "   / \n"
		+ space1 + "  /  \n"
		+ space1 + "/____\n";
}