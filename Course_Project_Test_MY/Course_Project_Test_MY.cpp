#include "Header.h"

int main()
{
	basikSettings();
	writeBorder();

	if (readSettings("Settings/settings.txt")) {  }
	else { masterOfSettings(); }
}

