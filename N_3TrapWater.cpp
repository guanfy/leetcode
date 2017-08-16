#include<iostream>
#include<algorithm>
using namespace std;

int trap_water(int *a,int len)
{
	if (len <= 2)
		return 0;
	int l = 0;
	int r = len - 1;
	int lmax = a[0];
	int rmax = a[len-1];
	int water = 0;

	while (l < r)
	{
		int cur = lmax >= rmax ? --r : ++l;
		if (l < r)
		{
			if ((min(lmax, rmax) - a[cur]) > 0)
			{
				water += (min(lmax,rmax) - a[cur]);
			}
		}
		//更新最大值
		lmax >= rmax ? rmax = (a[cur] > rmax ? a[cur] : rmax) : lmax = (a[cur] > lmax ? a[cur] : lmax);
	}
	return water;
}


int main()
{
	int a[20] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap_water(a, 12) << endl;
	int b[3] = { 2, 0, 2 };
	cout << trap_water(b, 3) << endl;
	return 0;
}