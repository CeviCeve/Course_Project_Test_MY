#include "Header.h"

int main()
{
	basikSettings();
	writeBorder();
	//draw();

	if (readSettings("Settings/settings.txt")) {}
	else { masterOfSettings(); }
}

