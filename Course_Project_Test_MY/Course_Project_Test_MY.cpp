#include "Header.h"

int main()
{
	job();
	_getch;
	_getch();
	//draw();
	basikSettings();
	//writeBorder();

	if (readSettings("Settings/settings.txt")) { myApp(); }
	else { masterOfSettings(); }
}

