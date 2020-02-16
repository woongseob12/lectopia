#ifndef __HOMEAUTOMATION_H__
#define	__HOMEAUTOMATION_H__
#include "Appliance.h"
#include "RiceCooker.h"

#define Appliance_MAX_CNT 5 // �ִ� ��� ������ ������ǰ�� ����

class HomeAutomation
{
private:
	RiceCooker * riceCookerArray[Appliance_MAX_CNT]; // ��ϵ� ��� ��ü�� ���� ���� �迭(������ü �Ҵ� �� �ּ�����)
	int riceCookerCnt; // ��ϵ� ��� ��ü�� ���� ����
public : 
	HomeAutomation(); // riceCookerArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, riceCookerCnt�� 0���� �ʱ�ȭ
	HomeAutomation(const HomeAutomation &r); // deep copy constructor
	~HomeAutomation(); // riceCookerArray�� ���� �Ҵ�� ��ü�� ��� ������

	// getter, setter member function
	RiceCooker ** getRiceCookerArray(); // riceCookerArray ��� �� ��ȯ �Լ�
	int getRiceCookerCnt() const ; // riceCookerCnt ��� �� ��ȯ �Լ�
	
	// member function
	HomeAutomation & operator=(const HomeAutomation &r); // ����(�Ҵ�)������ �����ε� �Լ�
	bool addAppliance(RiceCooker *ap);	// ������ǰ�� ��Ͽ� �߰�. ������ ��ǰ���� ����� ��� �Ұ�
	int searchMachine(string machineName); // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
	bool deleteAppliance(string machineName); // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����Ѵ�
	void listDisplayAppliance(); // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
	bool controlAppliance(string machineName);   // �ش� ������ǰ�� �����ϴ�
	void setStateAppliance(RiceCooker * ap); // �����ִ� ������ǰ�� ���¸� �����ϴ�
};
#endif
