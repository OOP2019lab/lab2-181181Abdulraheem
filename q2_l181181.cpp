#include <iostream>
#include <fstream>
#include "gitHubUser2.h"
using namespace std;

void readDataFromFile( gitHubUser2 * users, string filepath)
{
	ifstream read;
	read.open(filepath);
	int size ;
	read >> size;
	users = new gitHubUser2 [size];
	for (int i = 0 ; i < size ;i++)
	{
		read >> users[i].firstName;
		read >> users[i].userName;
		read >> users[i].email;
		read >> users[i].folderCount;
		int x = users[i].folderCount;
		for (int j = 0 ; j < x ; j++)
		{
			read >> users[i].gitHubFolders[j];
		}
	}

}


int main ()
{
	gitHubUser2 *users = nullptr;
	readDataFromFile(users, "Lab2.txt");
	if (users != nullptr)
		delete users;

	return 0;
}

