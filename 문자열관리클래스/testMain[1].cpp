#include "MyString.h"
int main()
{
	MyString ary[5]; // ��ü �迭
	MyString res; // ���ڿ��� ��� �ٿ��� ������ ��ü
	int i;
	cout << "5���� �����̸� �Է� : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i]; // �Է¿����� ���
	}
	cout << "ù��°�� �ι�° �� �� ���� �̸� : ";
	if (ary[0] > ary[1]) { // ���迬���� ���
		cout << ary[0] << endl; // ��¿����� ���
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4]; // ���������� ���
	cout << "��� ���ڿ� ���:" << res << endl;
	cout << "�迭���� ���ڿ� ���..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}

	MyString ob1("Have a nice day!!~");
	if (ob1.find("nice") == true) {
		cout << "�ش繮�ڿ��� �����մϴ�." << endl;
	}
	else {
		cout << "�ش繮�ڿ��� �������� �ʽ��ϴ�." << endl;
	}
	if (ob1.find("good") == true) {
		cout << "�ش繮�ڿ��� �����մϴ�." << endl;
	}
	else {
		cout << "�ش繮�ڿ��� �������� �ʽ��ϴ�." << endl;
	}
	MyString ob2("star");
	MyString res2;
	res2 = ob2 * 3;
	cout << res2;
	ob2 += " & moon";
	cout << ob2;

	(ob1 > ob2) ? cout << ob1 : cout << ob2; // �� ��ü�� �� �乮�ڿ� ����ϱ�

	return 0;
}