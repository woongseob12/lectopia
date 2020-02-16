#include<iostream>
using namespace std;
#include <string>
#include "HomeAutomation.h"

int menu(const char **menuList, int menuCnt); // ���޵� �޴��� ����ϰ� ��Ȯ�� �޴���ȣ�� �����ϴ� �Լ�
int controlMenuSelect(string message, int menuCnt); // ������ǰ�� ���º��� ó���� ���� �޴� �Լ�
void displayTitle(string title); // ó������ ���� ����ϱ� ���� Ÿ��Ʋ ����Լ� 
void screen(HomeAutomation &rHa); // �ָ޴��� ����ϰ� �޴��� ���ù޾� �ݺ������� �ָ޴��� ó���ϴ� �Լ�
void listDisplayAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ�� �������
void controlAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ �����ϱ�
void addAppliance(HomeAutomation &rHa); // ������ǰ ���
void deleteAppliance(HomeAutomation &rHa); // ������ǰ ����

int main()
{
	HomeAutomation homeAuto;
	screen(homeAuto);
	// �Ʒ� �ڵ�� ȭ�鿡 ����Ǵ� ��ȭ�� ������ ��������ڿ� ���Կ����� �Լ��� �׽�Ʈ �ϱ� ���� �ڵ��Դϴ�. 
	HomeAutomation temp1=homeAuto;  // ���� ������ �׽�Ʈ �ڵ�
	HomeAutomation temp2;
	temp2 = temp1;  // ���Կ����� �����ε� �Լ� �׽�Ʈ �ڵ� 
	return 0;
}

void screen(HomeAutomation &rHa)
{
	const char *menuList[]={"��� ����Ȯ�� ", "��� ���� ", "��� ��� ", "��� ���� ", "���� "};
	int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
	int menuNum;

	displayTitle("Ȩ ��� �ɾ�ý��� ����");
	while(true)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum==menuCnt) {break;}
		switch(menuNum)
		{
		case 1 : listDisplayAppliance(rHa); break;
		case 2 : controlAppliance(rHa); break;
		case 3 : addAppliance(rHa); break;
		case 4 : deleteAppliance(rHa); break;
		}
	}
	displayTitle("Ȩ ��� �ɾ�ý��� ����");
	return;
}
void listDisplayAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ�� �������
{
	displayTitle("��� ���� ����");
	if(rHa.getRiceCookerCnt() == 0)
	{
		cout << "��ϵ� ���� ��ǰ�� �����ϴ�" << endl;
	}
	else
	{
		rHa.listDisplayAppliance();
	}
	displayTitle("��� ���� ���� ����");
}
void controlAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ �����ϱ�
{
	string machineName;  // ��ǰ��
	bool res;

	displayTitle("��� ���� �ϱ�");
	if(rHa.getRiceCookerCnt() == 0)
	{
		cout << "��ϵ� ����� �����ϴ�.  ���� ����ϼ���." << endl;
		return;
	}
	
	cout << "* ������ ��ǰ�� �Է� : ";
	cin >> machineName;
	res=rHa.controlAppliance(machineName);
	if(res) 
	{
		cout << "��ܸ� : " << machineName << "�� ��� �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "��ܸ� : " << machineName << "�� ��� �����Ͽ����ϴ�." << endl << endl;
	}
}
void addAppliance(HomeAutomation &rHa) // ��� ���
{
	string machineName;  // ��ǰ��
	RiceCooker *ap;  // ������ǰ Ŭ������ ������ ����
	bool res;

	displayTitle("��� ��� �ϱ�");

	cout << "* ��ǰ�� �Է�( ��)ū���, 1ȣ��� ��) : ";
	cin >> machineName;
	
    ap=new RiceCooker(machineName);

	res=rHa.addAppliance(ap);
	if(res) 
	{
		cout << "��ܸ� : " << machineName << "�� ����� �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "��ܸ� : " << machineName << "�� ����� �����Ͽ����ϴ�." << endl << endl;
	}
}
void deleteAppliance(HomeAutomation &rHa) // ��� ����
{
	string machineName;  // ��ǰ��
	bool res;

	displayTitle("��� ���� �ϱ�");

	cout << "* ��ǰ�� �Է�( ��)ū���, 1ȣ��� ��) : ";
	cin >> machineName;
	
	res=rHa.deleteAppliance(machineName);
	if(res) 
	{
		cout << "��ܸ� : " << machineName << "�� ������ �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "��ܸ� : " << machineName << "�� ������ �����Ͽ����ϴ�." << endl << endl;
	}
}

int controlMenuSelect(string message, int menuCnt)
{
	int menuNum;

	while(true)
	{
		cout << message;
		cin >> menuNum;
		if(menuNum>0 && menuNum <= menuCnt){ break; }
	}
	return menuNum;
}

int menu(const char **menuList, int menuCnt)
{
	int i;
	int menuNum=0; /* �Էµ� �޴� ��ȣ ���� ����*/

	cout << endl << "==================================" << endl;
	for(i=0; i<menuCnt; i++)
	{
		cout << i+1 << "." << menuList[i] << endl;
	}
	cout << "==================================" << endl;
	while(menuNum<1 || menuNum>menuCnt)  /* ���� ���� ��ȣ�� �Էµ� �� ���� �ݺ�*/
	{
		cout <<"# �޴���ȣ�� �Է��ϼ��� : ";
		cin >> menuNum;
	}
	return menuNum;
}   
void displayTitle(string title) // ȭ�� Ÿ��Ʋ ��� �Լ�
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" <<endl;
}