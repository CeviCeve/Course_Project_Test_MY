#include "Header.h"

int main()
{
	//draw();
	basikSettings();
	//writeBorder();

	if (readSettings("Settings/settings.txt")) { myApp(); }
	else { masterOfSettings(); }
}

