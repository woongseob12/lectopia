#include <iostream>
using namespace std;
#include "MyAry.h"

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);

	MyArray score(3);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;

	for (i = 0; i < 4; i++) {
		cout << i + 1 << "�� �л��� ���� �Է� : ";
		cin >> temp;
		if (score.put(i, temp) == false) {
			cout << "�迭 ���� ����" << endl;
		}
	}
	for (i = 0; i < 4; i++) {
		res = score.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "�迭 �б� ����" << endl;
		}
	}
	cout << "��� : " << tot / 3.0 << endl;

	MyArray tempArray(score);
	MyArray tmp;
	tmp = score;

	return 0;
}