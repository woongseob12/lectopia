#ifndef __RICECOOKER_H__
#define	__RICECOOKER_H__
#include "Appliance.h"
using namespace std;

class RiceCooker : public Appliance
{
private:
	int machineState; // ��ǰ����(1:������, 2:����, 3:������, 4:�����)
public : 
	RiceCooker(); // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	RiceCooker(string machineName); // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	// getter, setter member function
	int getMachineState() const; // machineState ��� �� ��ȯ �Լ�
	void setMachineState(int machineState); // machineState ��� �ʱ�ȭ �Լ�
	// member function
	void stateView(); // ��ü�� ���� ���
	enum {NO_OPERATION=1, WARM, COOK, HEAT}; // ����� ���¸� ��Ÿ���� ������ ���
};
#endif