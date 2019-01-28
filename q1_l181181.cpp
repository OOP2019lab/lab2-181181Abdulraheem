// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "gitHubUser.h"
using namespace std;

bool Comparison(gitHubUser a, gitHubUser b)
{
	bool f = true;
	
	if (a.firstName == b.firstName)
	{
		cout << "Firstname is same\n";
	    f = false;
	}
	if (a.userName == b.userName)
	{
		cout << "Username is same\n";
	    f = false;
	}
	if (a.email == b.email)
	{
		cout << "Email is same\n";
	    f = false;
	}
	if (a.password == b.password)
	{
		cout << "Password is same\n";
	    f = false;
	}
	if (f == false)
		return false;
	else 
		return true;

}
gitHubUser* searchUser ( gitHubUser* users, int s , string userName)
{
	for (int i = 0; i < s ;i++)
	{
		if(users[i].userName == userName)
			return &users[i];
	}
	return nullptr;
}
bool exists(gitHubUser* arr, int s, string userName)
{
	bool f = true;
	for (int i = 0 ; i < s && f == true; i++)
	{
		if (userName == arr[i].userName)
			f = false;
	}
	if (f == false)
		return false;
	else 
		return true;
}
void inputFromUser(gitHubUser* arr, int s)
{
	cout << "--------------------\n";
	for (int i = 0 ; i < s ; i++)
	{
	     cout << "Enter the information of " << i + 1 << " user\n";
	     cout << "Enter the First name: ";
	     cin >> arr[i].firstName;
	     cout << "Enter the username: ";
	     cin >> arr[i].userName;
		 if (exists(arr,i,arr[i].userName) == false)
		 {
			 cout << "This username already exists, enter another username: ";
			 cin >> arr[i].userName;
		 }
	     cout << "Enter the email: ";
	     cin >> arr[i].email;
	     cout << "Enter the password: ";
	     cin >> arr[i].password;
		 cout << "\n";
	}
}


int main()
{
	gitHubUser a , b;
	cout << "Enter the Info of first user \n";
	cout << "Enter the first name: ";
	cin >> a.firstName;
	cout << "Enter the user name: ";
	cin >> a.userName;
	cout << "Enter the email: ";
	cin >> a.email;
	cout << "Enter the password: ";
	cin >> a.password;
	cout << "Enter the Info of second user \n";
	cout << "Enter the first name: ";
	cin >> b.firstName;
	cout << "Enter the user name: ";
	cin >> b.userName;
	cout << "Enter the email: ";
	cin >> b.email;
	cout << "Enter the password: ";
	cin >> b.password;
	bool flag = Comparison(a,b);
	if (flag == true)
		cout << "\nNothing is same\n";
	int s = 4;
	string x;
	gitHubUser *p = nullptr;
	gitHubUser *arr ;
	arr = new gitHubUser [s];
	inputFromUser( arr, s);
	cout << "Enter the username of the user: ";
	cin >> x;
	if (searchUser (arr , s , x) == nullptr)
		cout << "No alike info exist";
	else
	{
		p = searchUser (arr , s , x);
		cout<< "Relevant information \n";
		cout << "First name : "<< p->firstName;
		cout << "\nUsername : "<<p->userName;
		cout << "\nEmail : " << p->email;
		cout << "\nPassword : "<< p->password;
	}
	if (p!=nullptr)
	{
		delete p;
	}
	delete [] arr;
	arr = nullptr;

	return 0;
}

