#include "Header.h"

HANDLE honsole = GetStdHandle(STD_OUTPUT_HANDLE);
string letters[26];
CHORDS hords = getConsleChords();

void printUserCardController(int numCardStyle, SETTINGS settings, USER_SETTINGS userSettings, int color, int X)
{
	string thisData[4] = { "","","","" };
	string name[4] = { "","","","" };
	int ch = 0;
	if (settings.role) { thisData[ch] = userSettings.role2; name[ch] = "Роль:    "; ch++; }
	if (settings.age) { thisData[ch] = userSettings.age2; name[ch] = "Возраст: "; ch++; }
	if (settings.specialization) { thisData[ch] = userSettings.specialization2; name[ch] = "Профиль: "; ch++; }
	if (settings.sex) { thisData[ch] = userSettings.sex2; name[ch] = "Пол:     "; ch++; }
	for (int i = 0; i < 4; i++) if (name[i] == "") name[i] = "         ";

	string thisData2[5] = { "","","","","" };
	string name2[5] = { "","","","","" };
	int maxsize = 0;
	int ch2 = 0;
	for (int i = 0; i < 5; i++)
	{
		maxsize = max(maxsize, name2[i].size());
		if (settings.customizableChar[i] != "")
		{
			name2[ch2] = userSettings.customizableChar[i];
			ch2++;
		}
	}

	if (numCardStyle == 1)userCard1(name, name2, thisData, maxsize,color, X);
	if (numCardStyle == 2)userCard2(name, name2, thisData,  maxsize, color, X);
	if (numCardStyle == 3)userCard3(name, name2, thisData,  maxsize, color, X);

}

void userCard1(string name[], string name2[], string thisData[], int maxsize, int color, int X)
{
	string a="";
	for (int i = 0; i < X; i++)a += " ";
	SetConsoleTextAttribute(honsole,color);
	cout << a << "[================т----------------------------------------------]\n"
		<< a << "|    ________    | " << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize) << name2[0] << endl
		<< a << "|   /        \\   | " << "                         | " << setw(maxsize) << name2[1] << endl
		<< a << "|  |          |  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize) << name2[2] << endl
		<< a << "|  |          |  | " << "                         | " << setw(maxsize) << name2[3] << endl
		<< a << "|   \\        /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << name2[4] << endl
		<< a << "|   /\\______/\\   | " << "                         | " << endl
		<< a << "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << endl
		<< a << "[================L----------------------------------------------]";
}
void userCard2(string name[], string name2[], string thisData[], int maxsize, int color, int X)
{
SetConsoleTextAttribute(honsole,color);
string a = "";
for (int i = 0; i < X; i++)a += " ";
	cout << a << "[================т-----------------------------------------------]\n"
		<< a << "|    ________    | "   << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize) << name2[0] << endl
		<< a << "|   / ___  __\\   | "                 <<"                         | " << setw(maxsize)  << name2[1] <<endl
		<< a << "|  |_/"; SetConsoleTextAttribute(honsole, 51); cout << "   "; SetConsoleTextAttribute(honsole, color); cout << "=="; SetConsoleTextAttribute(honsole, 51); cout << "   "; SetConsoleTextAttribute(honsole, color);
	cout<< "|  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize) << name2[2] << endl
		<< a << "|  |          |  | " << "                         | " << setw(maxsize) << name2[3] << endl
		<< a << "|   \\        /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << name2[4] << endl
		<< a << "|   /\\______/\\   | " << "                         | " << setw(maxsize) << endl
		<< a << "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << setw(maxsize)<< endl
		<< a << "[================L----------------------------------------------]";
}
void userCard3(string name[], string name2[], string thisData[], int maxsize, int color, int X)
{
	string a = "";
	for (int i = 0; i < X; i++)a += " ";
	SetConsoleTextAttribute(honsole, color);
	cout << a << "[================т-----------------------------------------------]\n"
		<< a << "|    ________    | " << name[0] << setw(15) << thisData[0] << " | " << setw(maxsize)  << name2[0] << endl
		<< a << "|   / ___  __\\   | " << "                         | " << setw(maxsize)  << name2[1] << endl
		<< a << "|  |          |  | " << name[1] << setw(15) << thisData[1] << " | " << setw(maxsize)  << name2[2] << endl
		<< a << "|  |   /____\\ |  | " << "                         | " << setw(maxsize) << name2[3] << endl
		<< a << "|   \\   ____ /   | " << name[2] << setw(15) << thisData[2] << " | " << setw(maxsize) << name2[4] << endl
		<< a << "|   /\\______/\\   | " << "                         | " <<  endl
		<< a << "|  /          \\  | " << name[3] << setw(15) << thisData[3] << " | " << endl
		<< a << "[================L----------------------------------------------]";
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