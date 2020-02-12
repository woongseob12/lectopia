#include<iostream>
using namespace std;
class MyString {
private:
	char* str; // ���ڿ��� ������ �����͸��
	int len; // ���ڿ��� ���̸� ����
public:
	MyString(); // "", 0���� �ʱ�ȭ
	MyString(const char* cp); // �����ε�� ������
	MyString(const MyString& br); // ���� ������ (���� ����)
	~MyString(); // ���ҽ� �ݳ�
	MyString& operator=(const MyString& br); // ���� ����
	MyString operator+(const MyString& br); // ���� ������

	MyString operator*(int n); // ���ڿ��� n�� �ݺ��Ǵ� ���ڿ��� ����� ����
	MyString &operator+=(const char* p); // ���ڿ��� ���޵� ���ڿ��� �ٿ��� ����
	bool find(const char* p); // ���ڿ� ���� ���޵� ���ڿ��� �����ϴ°� �˻�
	bool operator>(const MyString& br); // ���迬���� ����Լ�(���� ��)
	bool operator==(const MyString& br); // ���̰����� �˻�
	bool operator<(const MyString& br); // ���� ª���� �˻�

	friend ostream& operator<<(ostream& os, MyString &); // ��¿����� ����Լ�
	friend istream& operator>>(istream& is, MyString &); // �Է¿����� ����Լ�
};
