#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int TwoSubArrMaxSum(vector<int> &nums)
{
	int len = nums.size();
	if (nums.empty() || len < 2)
		return 0;
	int *arr_R = new int[len];
	int maxsum = INT_MIN;
	int cur = 0;

	for (int i = len - 1; i > 0; i--)
	{
		cur += nums[i];
		if (cur > maxsum)
		{
			maxsum = cur;
		}
		arr_R[i] = maxsum;
		if (cur < 0)
			cur = 0;
	}

	int res = INT_MIN;
	maxsum = INT_MIN;
	cur = 0;
	for (int i = 0; i < len; i++)
	{
		cur += nums[i];
		maxsum = max(cur, maxsum);
		res = max(res,(maxsum+arr_R[i+1]));
		cur = cur < 0 ? 0 : cur;
	}
	delete[] arr_R;
	return res;
}

int main(){
	//vector<int> nums = {-1,3,4,-9,1,2};
	vector<int> nums = { 1,2,-4,3,2,-5};
	cout << TwoSubArrMaxSum(nums) << endl;
	return 0;
}