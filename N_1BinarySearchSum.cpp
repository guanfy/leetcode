#include<iostream>
using namespace std;

// 1.要查找的数一定在其中
int BinarySearch(int *a, int len, int target)
{
	int l = 0;
	int r = len - 1;
	int mid = 0;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (target > a[mid])
			l = mid + 1;
		else if (target < a[mid])
		{
			r = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

// 1. 查找最后一个小于key的元素
int BS_lastsmall(int *a, int len, int key)
{
	int l = 0;
	int r = len - 1;
	int m;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] >= key)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	return r;
}

//2. 查找第一个大于等于key的元素
int BS_firstlargeequal(int *a, int len, int key)
{
	int l = 0; 
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] < key)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return l;

}

//3. 查找最后一个小于等于key的元素
int BS_lastsmallequal(int *a, int len, int key)
{
	int l = 0;
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] > key)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	return r;
}
 
//4.查找第一个大于key的元素
int BS_firstlarge(int *a, int len, int key)
{
	int l = 0;
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] <= key)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return l;
}

//5. 查找第一个和key相等的元素
int BS_firstequal(int *a, int len, int key)
{
	int l = 0;
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] < key)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	if (l < len && a[l] == key)
		return l;
	return -1;
}


//６.查找最后一个与ｋｅｙ相等的元素
int BS_lastequal(int *a, int len, int key)
{
	int l = 0;
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] <= key)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	//ｒｉｇｈｔ是最后一个小于等于key的
	//ｌｅｆｔ是第一个大于ｋｅｙ的
	if (r >= 0 && a[r] == key)
	{
		return r;
	}
	return -1;

}
int main()
{

	return 0;
}