#include "Header.h"

int main()
{
	basikSettings();
	//writeBorder();
	//draw();
	SETTINGS settings;
	settings.setUserCard1(0, 1, 0, 1);
	userCard1(settings);
	_getch();
	if (readSettings("Settings/settings.txt")) {}
	else { masterOfSettings(); }
}

