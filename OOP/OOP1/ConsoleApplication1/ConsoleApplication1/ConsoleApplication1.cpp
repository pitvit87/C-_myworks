#include <iostream>
#include "Menu.h"
#include "DialogManager.h"

int main()
{
	Menu* m = new Menu();
	DialogManager* dm = new DialogManager();

	bool exit = false;
	do {
		m->display();
		switch (m->defineChoice())
		{
		case 1:
			dm->circleDialog();
			break;
		case 2:
			dm->rectangleDialog();
			break;
		case 3:
			dm->triangleDialog();
			break;
		case 4:
			exit = true;
			break;
		default:
			std::cout << "  Not such operation!\n";
			break;
		}

		if (exit)
			break;

	} while (m->allowContinue());

	delete m;
	delete dm;
	std::cout << "\n\nFinish!\n";
}

