#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	int sum = 0;
	int max = array[0];
	for (int i = 0; i < array.size();i++)
	{
		if (sum>0)
		{
			sum += array[i];
		}
		else
		{
			sum = array[i];
		}
		max = (max > sum ? max : sum);
	}
	return max;
}
void main()
{
	vector<int> array = { 6, -3, -2, 7, -15, 1, 2, 2 };
	cout<<FindGreatestSumOfSubArray(array);
}

