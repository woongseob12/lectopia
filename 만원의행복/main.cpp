#pragma warning (disable : 4996)
#include <iostream>
#include <cstring>
#include "Happy.h"
using namespace std;

int main()
{
	Happy a("ö��"), b("����"), w;
	char item[100];
	int price;
	char **useList;

	cout << "ö�̰� ���� ���ϴ�..." << endl;
	while (1) {
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) {
			break;
		}
		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}

	cout << endl << "������ ���� ���ϴ�..." << endl;
	while (1) {
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) {
			break;
		}
		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "���� ���ڴ�?" << endl;
	w = a.winner(b);
	cout << w.getName() << "�̰� �� " << w.getIndex() << "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�." << endl;

	cout << "��� ���� : ";
	useList = w.getList();
	for (int i = 0; i < w.getIndex(); i++) {
		cout << useList[i] << "  ";
	}

	return 0;
}