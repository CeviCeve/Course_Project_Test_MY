#include "Header.h"

int main()
{
	basikSettings();
	writeBorder();
	//draw();

	nameController("Damage Inc");
	_getch();
	_getch();

	if (readSettings("Settings/settings.txt")) { myApp(); }
	else { masterOfSettings(); }
}

