#include<iostream>
using namespace std;

bool isBadVersion(int version)
{
	if (version == 1)
		return true;
	else
		return false;
}

int firstBadVersion(int n) {
	int low = 1;
	int high = n;
	int ver = 0;
	while (low < high)
	{
		ver = low + (high - low) / 2;
		if (isBadVersion(ver))
		{
			high = ver;
		}
		else
		{
			low = ver + 1;
		}
	}
	return low;
}

int main()
{
	cout << firstBadVersion(5);
	return 0;
}