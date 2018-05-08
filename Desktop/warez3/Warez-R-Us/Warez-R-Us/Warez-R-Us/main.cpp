#include "WHManager.h"
int main()
{

	WHManager manager = WHManager();

	cout << manager.addUser("Origin", 0, "None", "Master", "12345", true) << endl;

	int choice = -1;

	while(choice != 0)
	{
		cout << "What do you want to do?" << endl;
		cout << "1: Log in and start system" << endl;
		cout << "0: Exit" << endl;
		cin >> choice;
		cin.ignore();

		if(choice == 1)
		{
			manager.login();
		}
	}
	
	return 0;
}