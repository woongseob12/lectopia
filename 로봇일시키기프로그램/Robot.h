#pragma once
class Robot
{
private:
	char *name;
	int energy;
	void errPrn(); // ������ ����- �����޽��� ���
public:
	Robot();  // name�� Null string("")����, energy�� 0���� �ʱ�ȭ
	~Robot(); // ���ҽ� �ݳ� �ڵ�
	Robot(const char *name, int energy = 0);
	Robot(const Robot& r);
	void go();              // ���� �޽��� ��� �� ������ 10 ����
	void back();            // ���� �޽��� ��� �� ������ 20 ����
	void turn();             // �� �޽��� ��� �� ������ 30 ����
	void jump();            // ���� �޽��� ��� �� ������ 40 ����
	void charge(int e);      // e�� ��ŭ ����(e�� �����̸� "�����δ� �����Ұ�...")
	char *getName();       // name����� �� ����
	void setName(const char *);   // name����� ���� ���޵� ���ڿ��� �� �ʱ�ȭ
	int getEnergy();         // energy����� �� ����  
	void setEnergy(int);     // energy����� ���� ���޵� ���ڷ� �� �ʱ�ȭ, ���޹��� ���ڰ� �����̸� e�� 0���� �ʱ�ȭ
};