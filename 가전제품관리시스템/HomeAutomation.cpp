#include "HomeAutomation.h"
#include <iostream>
using namespace std;

HomeAutomation::HomeAutomation()
{
	for (int i = 0; i < Appliance_MAX_CNT; i++) {
		riceCookerArray[i] = NULL;
	}
	riceCookerCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r)
{
	riceCookerCnt = r.riceCookerCnt;
	for (int i = 0; i < riceCookerCnt; i++) {
		riceCookerArray[i] = new RiceCooker;
		riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
		riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
		riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
	}
}

HomeAutomation::~HomeAutomation()
{
	cout << "home소멸자 시작" << endl;

	for (int i = 0; i < riceCookerCnt; i++) {
		delete riceCookerArray[i];
	}
	
	cout << "home 소멸자 끝" << endl;
}

RiceCooker ** HomeAutomation::getRiceCookerArray()
{
	return riceCookerArray;
}

int HomeAutomation::getRiceCookerCnt() const
{
	return riceCookerCnt;
}

HomeAutomation &HomeAutomation::operator=(const HomeAutomation &r)
{
	if (this == &r) { return *this; }
	for (int i = 0; i < riceCookerCnt; i++) {
		delete riceCookerArray[i];
	}
	riceCookerCnt = r.riceCookerCnt;
	for (int i = 0; i < riceCookerCnt; i++) {
		riceCookerArray[i] = new RiceCooker;
		riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
		riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
		riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
	}
	return *this;
}

bool HomeAutomation::addAppliance(RiceCooker *ap)
{
	if (riceCookerCnt >= Appliance_MAX_CNT) {
		cout << "등록 가능한 최대 개수를 초과 하였습니다." << endl;
		return false;
	}
	for (int i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == ap->getMachineName()) {
			cout << "동일한 이름의 밥솥은 등록 불가합니다." << endl;
			return false;
		}
	}
	riceCookerArray[riceCookerCnt] = new RiceCooker;
	riceCookerArray[riceCookerCnt] = ap;
	
	riceCookerCnt++;
	return true;	
}

int HomeAutomation::searchMachine(string machineName)
{
	int i;

	for (i = 0; i < riceCookerCnt; i++) {
		if (riceCookerArray[i]->getMachineName() == machineName) {
			break;
		}
	}
	if (i == riceCookerCnt) {
		return -1;
	}
	return i;
}

bool HomeAutomation::deleteAppliance(string machineName)
{
	int index = searchMachine(machineName);
	int i;

	if (index == -1) {
		cout << "** 해당하는 제품이 존재하지 않습니다.";
		return false;
	}
	else {
		for (i = index; i < riceCookerCnt - 1; i++) {
			riceCookerArray[i] = riceCookerArray[i + 1];
		}
		riceCookerArray[i] = NULL;
		riceCookerCnt--;

		return true;
	}
}

void HomeAutomation::listDisplayAppliance()
{
	for (int i = 0; i < riceCookerCnt; i++) {
		cout << i + 1 << ". ";
		riceCookerArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName)
{
	int index = searchMachine(machineName);
	
	if (index == -1) {
		cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
		return false;
	}
	else {
		if (riceCookerArray[index]->getPowerFlag() == false) {
			riceCookerArray[index]->turnOn();
		}
		setStateAppliance(riceCookerArray[index]);
		return true;
	}
}

void HomeAutomation::setStateAppliance(RiceCooker * ap)
{
	int stateNum;

	do
	{
		cout << "변경할 상태를 입력하시오(1.NO_OPERATION 2. WARM 3. COOK 4. HEAT) : ";
		cin >> stateNum;
	} while (stateNum < 1 || stateNum>4);
	ap->setMachineState(stateNum);
	ap->stateView();
}
