#include <iostream>
#include <string>
using namespace std;

class people
{
public:
	people()
	{
		cout << "���캯��people" << endl;
	}
	virtual void dowork()
	{
		cout << "����dowork" << endl;
	}
	
};

class worker:public people
{
public:
	worker()
	{
		cout << "���캯��worker" << endl;
	}
	virtual void dowork()
	{
		cout << "����dowork" << endl;
	}
	
};
class tool:public worker
{
public:
	tool()
	{
		 cout << "���캯��tool" << endl;
	}
	void dowork()
	{
		cout << "tool" << endl;
	}
};
void main2()
{
	//ʵ�����������ָ��ʵ�ֶ�̬Ч��
	worker *w = new tool;//����ָ��  �������
	
	w->dowork();
}