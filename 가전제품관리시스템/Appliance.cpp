#include "Appliance.h"
#include <iostream>

Appliance::Appliance()
{
	machineName = "";
	powerFlag = false;
}

Appliance::Appliance(string machineName, bool powerFlag)
{
	this->machineName = machineName;
	this->powerFlag = powerFlag;
}

string Appliance::getMachineName() const
{
	return machineName;
}

bool Appliance::getPowerFlag() const
{
	return powerFlag;
}

void Appliance::setMachineName(string machineName)
{
	this->machineName = machineName;
}

void Appliance::setPowerFlag(bool powerFlag)
{
	this->powerFlag = powerFlag;
}

bool Appliance::turnOn()
{
	if (powerFlag == true) {
		return false;
	}
	else {
		powerFlag = true;
		return true;
	}
}

bool Appliance::turnOff()
{
	if (powerFlag == false) {
		return false;
	}
	else {
		powerFlag = false;
		return true;
	}
}

void Appliance::stateView()
{
	cout << "ID : " << getMachineName() << "/ state : " << getPowerFlag();
}