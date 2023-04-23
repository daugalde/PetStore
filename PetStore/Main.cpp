#include <string>
#include "Menu.h"
#include "AppManager.h"

int main() {

	AppManager manager;

	manager.InitStoreLoad();

	int yourchoice = 0;

	string confirm = "";

	Menu::Displaymenu();

	do
	{
		getline(cin, confirm);

		if (confirm.length() == 0) {

			Menu::Displaymenu();
			confirm = " ";
			continue;
		}

		switch (confirm[0])
		{
		case '1':
			manager.DataManager();
			yourchoice = 2;
			break;
		case '2':
			manager.ShowReports();
			yourchoice = 2;
			break;
		case '3':
			cout << "Desea Salir ? Presione Y\n";
			getline(cin, confirm);
			if (confirm == "Y" || confirm == "y")
			{
				confirm = "";
			}
			else {
				confirm = " ";
			}
		default:
			Menu::Displaymenu();
			break;
		}

	} while (confirm.length() != 0);

	return 0;
}