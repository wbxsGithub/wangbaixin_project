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
	virtual~people()
	{
		cout << "����~people" << endl;
	}
};

class worker :public people
{
public:
	worker()
	{
		cout << "���캯��worker" << endl;
	}
	void dowork()
	{
		cout << "����dowork" << endl;
	}
	void wash()
	{
		cout << "ϴԡ" << endl;
	}
	 ~worker()
	{
		cout << "����~worker" << endl;
	}
};
class tool :public worker
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
	~tool()
	{
		cout << "����~tool" << endl;
	}
};
void main()
{
	
	//ʵ����������ʵ�� ���ء�

	//1.�������أ�
	tool *t = new tool;
	t->dowork();//���������ຯ��������������

	cout << endl;
	//2.ʵ��������
	worker *w = new tool;
	delete w;
	cout << endl;
	people *p = new worker;
	delete p;//����ʱֻ����������ģ���������������tool�������ڴ�й©��Ϊ�˽���ڴ�й©����������
	
}