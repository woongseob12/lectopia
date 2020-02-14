#include "Happy.h"
using namespace std;

Happy::Happy(string np, int money)
{
	this->name = np;
	this->money = money;
	for (int i = 0; i < MAX_ITEM_LIST; i++) {
		this->list[i] = NULL;
	}
	this->index = 0;
}

Happy::Happy(Happy &r)
{
	this->name = r.name;
	this->money = r.money;
	for (int i = 0; i < r.index; i++) {
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i],r.list[i]);
	}
	for (int i = r.index; i < MAX_ITEM_LIST; i++) {
		this->list[i] = NULL;
	}
	this->index = r.index;
}

Happy::~Happy()
{
	for (int i = 0; i < index; i++) {
		delete[] this->list[i];
	}
}

Happy &Happy::operator=(Happy &r)
{
	if (this == &r) { return *this; }
	this->name = r.name;
	this->money = r.money;
	for (int i = 0; i < this->index; i++) {
		delete[] this->list[i];
	}
	for (int i = 0; i < r.index; i++) {
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}
	this->index = r.index;
	
	return *this;
}

void Happy::use(char *lp, int n)
{
	this->money = this->money - n;
	this->list[index] = new char[strlen(lp)+1];
	strcpy(this->list[index], lp);
	this->index += 1;
}

Happy &Happy::winner(Happy &r)
{
	if (this->money >= r.money) {
		return *this;
	}
	else {
		return r;
	}
}

void Happy::setName(string &name)
{
	this->name = name;
}

string &Happy::getName()
{
	return this->name;
}

void Happy::setMoney(int money)
{
	if (money < 0) {
		this->money = 0;
	}
	else {
		this->money = money;
	}
}

int Happy::getMoney()
{
	return this->money;
}

char **Happy::getList()
{
	return this->list;
}

int Happy::getIndex()
{
	return this->index;
}