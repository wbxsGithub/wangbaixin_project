#include <iostream>
#include <string>
using namespace std;
//ģ��������ĵݹ���

void unback()
{
	cout << "�����Ŀհ�" << endl;
}
template<class firstArg, class...args> void unback(firstArg f, args...a)
{
	cout << f << endl;
	unback(a...);
}

void main()
{
	unback(1, 2, "fag", 4, 5);
}