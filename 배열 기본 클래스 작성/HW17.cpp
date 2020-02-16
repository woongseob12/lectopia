#include "MyAry.h"


MyArray::MyArray(int s)
{
	ary = new int[s];
	if (s < 0) {
		size = 0;
	}
	else {
		size = s;
	}
}

MyArray::MyArray(const MyArray &br)
{
	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
}

MyArray &MyArray::operator=(const MyArray &br)
{
	if (this == &br) { return *this; }
	delete[] ary;
	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
	return *this;
}

bool MyArray::put(int index, int val)
{
	if (index < 0 || index >= size) {
		return false;
	}
	else {
		ary[index] = val;
		return true;
	}
}

bool MyArray::get(int index, int &getdata)
{
	if (index < 0 || index >= size) {
		return false;
	}
	else {
		getdata = ary[index];
		return true;
	}
}

int MyArray::getSize()
{
	return size;
}

int * MyArray::getAry(void)
{
	return ary;
}
