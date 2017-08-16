#include<iostream>
using namespace std;

// 1.Ҫ���ҵ���һ��������
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

// 1. �������һ��С��key��Ԫ��
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

//2. ���ҵ�һ�����ڵ���key��Ԫ��
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

//3. �������һ��С�ڵ���key��Ԫ��
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
 
//4.���ҵ�һ������key��Ԫ��
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

//5. ���ҵ�һ����key��ȵ�Ԫ��
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


//��.�������һ���������ȵ�Ԫ��
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
	//�����������һ��С�ڵ���key��
	//������ǵ�һ�����ڣ�����
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