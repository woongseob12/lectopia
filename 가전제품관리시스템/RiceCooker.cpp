#include "RiceCooker.h"
#include <iostream>

RiceCooker::RiceCooker():Appliance()
{
	machineState = 1;
}

RiceCooker::RiceCooker(string machineName):Appliance(machineName)
{
	machineState = 1;
}

int RiceCooker::getMachineState() const
{
	return machineState;
}

void RiceCooker::setMachineState(int machineState)
{
	this->machineState = machineState;
}

void RiceCooker::stateView()
{
	Appliance::stateView();
	cout << "/ MachineState : ";
	switch (machineState)
	{
	case NO_OPERATION: cout << "NO_OPERATION" << endl; break;
	case WARM: cout << "WARM" << endl; break;
	case COOK: cout << "COOK" << endl; break;
	case HEAT: cout << "HEAT" << endl; break;
	default:
		break;
	}
}
