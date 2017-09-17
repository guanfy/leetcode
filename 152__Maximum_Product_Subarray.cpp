#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
	int len = nums.size();
	if (len <= 0)
		return 0;
	if (len == 1) return nums[0];
	
	int maxpro = nums[0];
	int minpro = nums[0];
	int max_res = nums[0];

	for (int i = 1; i < len; i++)
	{
		int a = maxpro * nums[i];
		int b = minpro * nums[i];

		maxpro = max(nums[i], max(a, b));
		minpro = min(nums[i], min(a, b));

		max_res = max(maxpro, max_res);
	}
	return max_res;
}


int main()
{

	return 0;
}