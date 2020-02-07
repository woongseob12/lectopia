#include <iostream>
#include "Robot.h"
using namespace std;

int input();
void input(Robot *, int);
void work(Robot *, int);
void output(Robot *, int);

int main()
{
	int rCnt;
	Robot *rp;

	rCnt = input();
	rp = new Robot[rCnt];

	input(rp, rCnt);
	work(rp, rCnt);
	output(rp, rCnt);
	delete[] rp;
}

int input()
{
	int cnt;
	
	while (1) {
		cout << "������ �κ� ����� �Է��Ͻÿ� : ";
		cin >> cnt;
		if (!cin || cnt < 0) {
			cin.clear();
			cin.ignore(INTMAX_MAX, '\n');
		}
		else {
			cin.ignore(INTMAX_MAX, '\n');
			break;
		}
	}
	return cnt;
}

void input(Robot *p, int rCnt)
{
	char rName[100];
	int rEnergy;

	for (int i = 0; i < rCnt; i++) {
		cout << i + 1 << "�� �κ����� �Է��Ͻÿ� : ";
		cin.getline(rName, sizeof(rName));
		p[i].setName(rName);
		
		cout << p[i].getName() << "�� ������ ���� �Է��Ͻÿ� : ";
		cin >> rEnergy;
		p[i].setEnergy(rEnergy);
		cin.ignore(INTMAX_MAX, '\n');
	}
}

void work(Robot *p, int rCnt)
{
	char rName[100];
	int rMotion = 0;
	int rEnergy;
	int rNumber;

	while (1) {
		while (1) {
			rNumber = -1;

			cout << "# �κ��� ����(";
			for (int i = 0; i < rCnt; i++) {
				if (i == 0) {
					cout << p[i].getName();
				}
				else {
					cout <<", " << p[i].getName();
				}
			}
			cout << ") : ";

			cin.getline(rName, sizeof(rName));
			if (rName[0] == '\0') {
				break;
			}

			for (int i = 0; i < rCnt; i++) {
				if (strcmp(rName, p[i].getName()) == 0) {
					rNumber = i;
				}
			}

			if (rNumber != -1) {
				break;
			}
		}

;		if (rName[0] == '\0') {
			return;
		}
		else {
			cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
			do {
				cin >> rMotion;
				cin.ignore(INTMAX_MAX, '\n');
			} while (!cin || (rMotion < 1 || rMotion > 5));
		}
		switch (rMotion)
		{
		case 1: p[rNumber].go(); break;
		case 2: p[rNumber].back(); break;
		case 3: p[rNumber].turn(); break;
		case 4: p[rNumber].jump(); break;
		case 5:
			cout << "# ������ �������� �Է� : ";
			cin >> rEnergy;
			cin.ignore(INTMAX_MAX, '\n');
			p[rNumber].charge(rEnergy);
			cout << p[rNumber].getName() << " ������ " << rEnergy << " ����..." << endl;
			break;
		default:
			break;
		}
	}
}

void output(Robot *p, int rCnt)
{
	cout << "\n";
	for (int i = 0; i < rCnt; i++) {
		cout << i + 1 << " " << p[i].getName() << " : " << p[i].getEnergy() << endl;
	}
}