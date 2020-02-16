#pragma once
#include <iostream>

class MyArray
{
private:
	int *ary;
	int size;
public:
	MyArray() { ary = NULL; size = 0; }
	MyArray(int s);
	MyArray(const MyArray &br);
	~MyArray() { delete[] ary; }
	MyArray &operator=(const MyArray &br);
	bool put(int index, int val);
	bool get(int index, int &getdata);
	
	int getSize();
	int *getAry(void);
};
