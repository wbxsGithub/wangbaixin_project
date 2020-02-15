#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;
static_assert(sizeof(char*)==4, "integer is not 32 ");
class vec
{
	int *val;
	int size;
public:
	//��ͬʱ�г�ʼ�������б��list��vector������ʱ������ѡ��initializer_list
	vec(initializer_list<double> ve)//���췽��
	{
		size = ve.size();
		val = new int[ve.size()];
		for (int i = 0; i < ve.size(); i++)
		{
			val[i] = *(ve.begin() + i);
		}
	}
	int& operator [](unsigned int index)
	{
		assert(index <= 0 || index>size);
		return val[index];
	}
};
void main()
{
	vec ve({1,2,3,4,5,6,7});
	cout<<ve[2]<<endl;
	

}