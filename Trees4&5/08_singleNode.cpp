/*i have not founded this question on any platform but understands and learnt a new concept*/
#include <bits/stdc++.h>
using namespace std;
int hasOnlyOneChild(int pre[], int size)
{
	int min, max;
	if (pre[size - 1] > pre[size - 2])
	{
		max = pre[size - 1];
		min = pre[size - 2];
	}
	else
	{
		max = pre[size - 2];
		min = pre[size - 1];
	}
	for(int i = size - 3; i >= 0; i--)
	{
		if (pre[i] < min)
			min = pre[i];
		else if (pre[i] > max)
			max = pre[i];
		else
			return false;
	}
	return true;
}


int main()
{
	int pre[] = { 8, 3, 5, 7, 6 };
	int size = sizeof(pre) / sizeof(pre[0]);
	
	if (hasOnlyOneChild(pre,size))
		cout <<"Yes";
	else
		cout <<"No";
		
	return 0;
}

