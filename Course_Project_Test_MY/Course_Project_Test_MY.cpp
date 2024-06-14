#include "Header.h"

int main()
{
	//draw();
	basikSettings();
	//job(0);
	writeBorder();

	if (readSettings("Settings/settings.txt")) { myApp(); }
	else { masterOfSettings(); }
}

