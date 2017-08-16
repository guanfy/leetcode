#include<iostream>
#include<vector>
using namespace std;

int findLongest_n_2(vector<int> A, int n) 
{
	if (A.size() <= 0 || n <= 0)
		return 0;
	vector<int> h(n,0);
	h[0] = 1;
	int max_h = 1;
	for (int i = 1; i < n; i++)
	{
		int max_hi = 1;
		for (int j = i - 1; j >= 0; j--)
		{ 
			if (A[j] < A[i])
			{
				h[i] = h[j] + 1;
			}
			if (max_hi < h[i])
			{
				max_hi = h[i];
			}
			h[i] = max_hi;
		}
		if (max_h < max_hi)
		{
			max_h = max_hi;
		}
 	}
	return max_h;
}

int BinarySearch(vector<int>arr, int target)
{
	int n = arr.size();
	if (target > arr[n - 1])
	{
		return -1;
	}
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int findLongest_n_logn(vector<int> A, int n)
{
	if (A.size() <= 0 || n <= 0)
	{
		return 0;
	}
	vector<int> h;
	h.push_back(A[0]);
	for (int i = 1; i < n; i++)
	{
		int cur = BinarySearch(h, A[i]);
		if (cur == -1)
		{
			h.push_back(A[i]);
		}
		else
		{
			h[cur] = A[i];
		}
	}
	return h.size();
}


int main()
{
	vector<int> v = { 1, 3, 6, 4, 5, 7, 9 };
	cout<<findLongest_n_2(v, 7)<<endl;
	cout << findLongest_n_logn(v, 7) << endl;
	vector<int> v2 = {3,1,0};
	cout << findLongest_n_2(v2, 3) << endl;
	cout << findLongest_n_logn(v2, 3) << endl;
	return 0;
}