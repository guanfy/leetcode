#include<iostream>
#include<vector>
using namespace std;

int longest_increasing_subseq(vector<int> arr)
{
	int len = arr.size();
	if (len <= 0)
		return 0;
	vector<int> h; //辅助数组，记录以arr[i]结尾的最长子序列的长度
	h.push_back(1);
	int max_len = 1;
	for (int i = 1; i < len; i++)
	{
		int h_cur = 0;
		int h_max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				h_cur = h[j] + 1;			
			}
			else
			{
				h_cur = 1;
			}
			if (h_cur > h_max)
			{
				h_max = h_cur;
			}
		}
		h.push_back(h_max);
		if (h[i] > max_len)
		{
			max_len = h[i];
		}
	}
	return max_len;
	
}

int BinarySearch(vector<int> arr,int target)
{
	int len = arr.size();
	if (target > arr[len - 1])
		return -1;
	int L = 0;
	int R = len - 1;
	while (L < R)
	{
		int mid = (L + R) / 2;
		if (arr[mid] < target)
		{
			L = mid + 1;
		}
		else
		{
			R = mid;
		}
	}
	return L;
}

int longest_increasing_subseq_nlogn(vector<int> arr)
{
	int len = arr.size();
	if (len <= 0)
		return 0;
	vector<int> h;
	h.push_back(arr[0]);
	for (int i = 1; i < len; i++)
	{
		int cur = BinarySearch(h, arr[i]);
		if (cur == -1)
			h.push_back(arr[i]);
		else
		{
			h[cur] = arr[i];
		}
	}
	return h.size();
}

int main()
{
	vector<int> v = { 2,1,6,4,5,2,7,4 };
	int i = longest_increasing_subseq_nlogn(v);
	//int i = longest_increasing_subseq(v);
	//cout << i << endl;
	vector<int> v1 = { 1,3,4,6,9 };
	cout << BinarySearch(v1, 7);


	return 0;
}