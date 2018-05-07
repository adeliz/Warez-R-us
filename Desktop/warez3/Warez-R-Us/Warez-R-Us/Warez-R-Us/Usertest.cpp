#include <iostream>
#include<string>
#include "user.h"

using namespace std;

// Checkar så att change password fungerar!
int main() 
{
	User *user1 = new User("apa", 1337, "beast", "snus", "123fem", 0);
		
	string testname = "";
	bool checkCurrentPw;
	bool checkPW;
	string currentPw = "";

	for (int i = 0; i < 1;)
	{
		cout << "please input your old password" << endl;
		cin >> currentPw;

		// Detta kommer man fortfarande inte veta vad som är fel på
		if (user1->checkPassword(currentPw)) {

			cout << "correct password" << endl;
			cout << endl << "choose new pw between 4-8 letters." << endl;
			cin >> testname;

			if (user1->changePassword(testname))
			{
				i++;
				cout << "Password changed" << endl;
				cout << currentPw << endl;
			}

			else
				cout << "Unallowed new password" << endl;
		}
		else
			cout << "Wrong password" << endl;
	}

	cin >> "press enter to continue";

	return 0;
}











