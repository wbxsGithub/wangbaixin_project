#include <iostream>
#include <string>
using namespace std;
//����ģ��  ��ģ��
//����class�ȼ���typename
//�������ͣ���ģ���������ȫ��ͬ����ͨ�����ĺ���
template<class T> T Lmax(T a, T b)//���ݲ������� ��ʽ�Ƶ����Ͳ�ͬ�����Ƶ�
{
	return a > b ? a : b;
}
template<class T, class B> T Lmax(T a, B b)//�����������͹�����
{
	return a > b ? a : b;
}
template<int x, class T, class B> T Lmax(T a, B b)//���Զ����������������򴫵ݲ���
{
	return a > b ? a : b;
}
void main()
{
	int a = 1, b = 2;
	//��ʽ�Ƶ�
	cout << sizeof( Lmax<double>(a, b) );
	//��ʽ�Ƶ��������ֳɵĺ�������ģ���Ƶ�
	cout << Lmax(a, b);
	//��ʾģ��
	cout << Lmax<>(a, b);
}