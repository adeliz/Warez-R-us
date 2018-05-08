#include "TruckManager.h"

int main()
{
	TruckManager TM = TruckManager();

	Truck temp1 = Truck("aaa", "Stockholm", 80, 200, 1000);
	Truck temp2 = Truck("bbb", "Falun", 70, 50, 900);
	Truck temp3 = Truck("ccc", "Kiruna", 60, 20, 100);

	TM.addTruck(temp1);
	TM.addTruck(temp2);
	TM.addTruck(temp3);
	
	cout << TM.list() << endl;
	cout << "#################################" << endl;
	system("PAUSE");

	TM.getTruckAt(0).getStorage()->addFood("Apple", "An apple", "FAncy", 2, 10, "Green", 3);
	TM.getTruckAt(0).getStorage()->addFood("Apple", "An apple", "norMAL", 2, 5, "Red", 3);
	TM.getTruckAt(0).getStorage()->addFood("Orange", "An orange", "Fancy", 2, 15, "sweet", 3);

	TM.getTruckAt(0).getStorage()->addMisc("Void", "a void", "None", -10, 1000, "#%¤#¤&¤");

	cout << TM.getTruckAt(0).getStorage()->getAll() << endl;
	cout << "////////////////////////////////////////////////" << endl;

	cout << TM.getTruckAt(0).getStorage()->removeAt(3);
	cout << TM.getTruckAt(0).getStorage()->getAll() << endl;

	system("PAUSE");
	return 0;
}