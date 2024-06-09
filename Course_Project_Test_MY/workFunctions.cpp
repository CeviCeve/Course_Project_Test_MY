#include "Header.h"

int columns, rows;
string pytCorp1 = "VERY POPYLAR COMPANY";
const HANDLE hhCon = GetStdHandle(STD_OUTPUT_HANDLE);


void basikSettings()
{
    system("mkdir Settings");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    UnwrapScreen();
}

static void UnwrapScreen()
{
    COORD NewSBSize;
    SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
    NewSBSize = GetLargestConsoleWindowSize(hhCon);
    SetConsoleScreenBufferSize(hhCon, NewSBSize);
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
    SetConsoleWindowInfo(hhCon, TRUE, &DisplayArea);
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

CHORDS getConsleChords()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    CHORDS chords;
    chords.y = rows;
    chords.x = columns;
    //cout << "columns: " << columns << std::endl;
    //cout << "rows: " << rows << std::endl;
    return chords;
}

void writeBorder()
{
    system("cls");

    CHORDS chords = getConsleChords();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int chislo = 1;
    

    setCursorPosition((((chords.x - pytCorp1.size()) - 1) / 2), chords.y / 2);
    Sleep(100);

    for (int i = 0; i < pytCorp1.size(); i++)
    {
        if (chislo > 15)chislo = 1;
        SetConsoleTextAttribute(hConsole, 14);
        chislo++;
        cout << pytCorp1[i];
        Sleep(50);
    }
    Sleep(800);

    for (int i = 0; i < pytCorp1.size(); i++)
    {
        setCursorPosition((((chords.x - pytCorp1.size())-1) / 2 + i), chords.y / 2);
        cout << " ";
        Sleep(50);
    }
    Sleep(800);

}

int gotoThisLine(int maxSize,int positionCursore ,int tapp)
{
    int inThisLine;

    if (tapp == 80)
        if (positionCursore == maxSize - 1)
            inThisLine = 0;
        else inThisLine = positionCursore + 1;

    else if (tapp == 72)
        if (positionCursore == 0)
            inThisLine = maxSize - 1;
        else inThisLine = positionCursore - 1;

    else inThisLine = positionCursore;

    return inThisLine;
}

void draw()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
    for (int k = 1; k < 255; k++)
    {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << k << " I want to be nice today!" << endl;
    }
}

bool isValidEmail(const std::string& email)
{
    // Определите регулярное выражение
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // Проверьте, соответствует ли введенная строка регулярному выражению
    return regex_match(email, pattern);
}