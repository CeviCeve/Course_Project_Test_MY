#include "Header.h"

int columns, rows;
string pytCorp1 = u8"VERY POPYLAR COMPANY";



void allLang()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "en_US.UTF-8");

    Function function;
    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void getConsleChords()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //cout << "columns: " << columns << std::endl;
    //cout << "rows: " << rows << std::endl;
}

void writeBorder()
{

    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int chislo = 1;
    getConsleChords();

    setCursorPosition((((columns - pytCorp1.size()) - 1) / 2), rows / 2);
    Sleep(100);

    for (int i = 0; i < pytCorp1.size(); i++)
    {
        if (chislo > 15)chislo = 1;
        SetConsoleTextAttribute(hConsole, 6);
        chislo++;
        cout << pytCorp1[i];
        Sleep(50);
    }
    Sleep(800);

    for (int i = 0; i < pytCorp1.size(); i++)
    {
        setCursorPosition((((columns - pytCorp1.size())-1) / 2 + i), rows / 2);
        cout << " ";
        Sleep(50);
    }
    Sleep(800);

    _getch();
}