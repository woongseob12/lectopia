#pragma warning(disable : 4996)
#include <iostream>
#include "Robot.h"
using namespace std;

Robot::Robot()
{
	this->name = new char[1];
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::~Robot()
{
	delete[] this->name;
}

Robot::Robot(const char *name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot& r)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}

void Robot::go()
{
	if (this->energy >= 10) {
		cout << this->name << " 전진" << endl;
		this->energy -= 10;
	}
	else {
		errPrn();
	}
}

void Robot::back()
{
	if (this->energy >= 20) {
		cout << this->name << " 후진" << endl;
		this->energy -= 20;
	}
	else {
		errPrn();
	}
}

void Robot::turn()
{
	if (this->energy >= 30) {
		cout << this->name << " 턴" << endl;
		this->energy -= 30;
	}
	else {
		errPrn();
	}
}

void Robot::jump()
{
	if (this->energy >= 40) {
		cout << this->name << " 점프" << endl;
		this->energy -= 40;
	}
	else {
		errPrn();
	}
}

void Robot::charge(int e)
{
	if (e >= 0) {
		this->energy += e;
	}
	else {
		cout << "음수 에너지양은 충전이 불가능합니다." << endl;
	}
}

char* Robot::getName()
{
	return this->name;
}

void Robot::setName(const char *cP)
{
	delete[] this->name;
	this->name = new char[strlen(cP) + 1];
	strcpy(this->name, cP);
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int e)
{
	if (e < 0) {
		this->energy = 0;
	}
	else {
		this->energy = e;
	}
}

void Robot::errPrn()
{
	cout << "에너지가 부족합니다" << endl;
}