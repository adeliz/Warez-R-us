#include "User.h"

User::User(string name, int SSN, string gender, string username, string password, bool adminRights)
	:Person(name,SSN,gender)
{

	this->username = username;
	this->password = password;
	this->adminRights = adminRights;

}

User::~User()
{
}

string User::getUserName() const
{
	return this->username;
}

bool User::getAdmin() const
{
	return this->adminRights;
}


bool User::changePassword(string newPassword)
{

		if (newPassword.length() > 3 && newPassword.length() < 9)
		{
			this->password = newPassword;
			return true;
		}
	else
	return false;
	
}

bool User::checkPassword(string currentPassword)
{
	if (currentPassword == this->password)
	{
		return true;
	}
	else
		return false;
}

void User::setAdminRights()
{
	this->adminRights = true;
}

void User::removeAdminRights()
{
	this->adminRights = false;
}
