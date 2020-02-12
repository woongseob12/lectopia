#pragma warning (disable : 4996)
#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	str = new char[1];
	strcpy(str, "");
	len = 0;
}

MyString::MyString(const char* cp)
{
	len = strlen(cp);
	str = new char[len + 1];
	strcpy(str, cp);
}

MyString::MyString(const MyString& br)
{
	len = br.len;
	str = new char[len + 1];
	strcpy(str, br.str);
}

MyString::~MyString()
{
	delete[] str;
}

MyString& MyString::operator=(const MyString& br)
{
	if (this == &br) {
		return *this;
	}
	len = br.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, br.str);
	return *this;
}

MyString MyString::operator+(const MyString& br)
{
	MyString temp;

	temp.len = len + br.len;
	delete[] temp.str; 
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, str);	
	strcat(temp.str, br.str);

	return temp;
}

MyString MyString::operator*(int n)
{
	MyString temp;
	temp.len = this->len * n;
	delete[] temp.str;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, this->str);
	for (int i = 0; i < n - 1; i++) {
		strcat(temp.str, this->str);
	}
	return temp;
}

MyString &MyString::operator+=(const char* p)
{
	char *temp;
	temp = new char[len + 1];
	strcpy(temp, str);
	len += strlen(p);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, temp);
	delete[] temp;
	strcat(str, p);

	return *this;
}

bool MyString::find(const char* p)
{
	char *findWord = strstr(this->str, p);

	if (findWord == NULL) {
		return false;
	}
	else {
		return true;
	}
}

bool MyString::operator>(const MyString& br)
{
	if (len > br.len) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator==(const MyString& br)
{
	if (len == br.len) {
		return true;
	}
	else {
		return false;
	}
}

bool MyString::operator<(const MyString& br)
{
	if (len < br.len) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& os, MyString &br)
{
	cout << br.str << "(" << br.len << ")";

	return os;
}

istream& operator>>(istream& is, MyString &br)
{
	char temp[80];
	cin >> temp;
	delete[] br.str;
	br.str = new char[strlen(temp) + 1];
	strcpy(br.str, temp);
	br.len = strlen(br.str);

	return is;
}