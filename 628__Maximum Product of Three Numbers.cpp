#include<iostream>
#include <algorithm>
#include<vector>
#include<climits>
using namespace std;

//未考虑乘积中有两个负数的情况，如：｛-4，-3，-2，-1，6｝
//时间复杂度太高，不适合
void selectsort(vector<int> &arr)
{
	int len =arr.size();

	for (int i = 0; i < len-1; i++)
	{
		int max_i = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j]>arr[max_i])
			{
				max_i = j;
			}
		}
		if (max_i != i)
		{
			int temp = arr[i];
			arr[i] = arr[max_i];
			arr[max_i] = temp;
		}
	}
}
//1.排序，
int maximumProduct1(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	int len = nums.size();
	int a = nums[0] * nums[1] * nums[len - 1];
	int b = nums[len - 1] * nums[len - 2] * nums[len - 3];
	return a > b ? a : b;
}
// 2. 找出最大三个数，最小两个数，比较乘积的大小
int maximumProduct(vector<int>& nums) {
	
	int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

	for (int i = 0; i< nums.size(); i++)
	{
		if (nums[i]<min1)
		{
			min2 = min1;
			min1 = nums[i];
		}
		else if (nums[i] <= min2)
		{
			min2 = nums[i];
		}

		if (nums[i]>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}
		else if (nums[i] >= max2)
		{
			max3 = max2;
			max2 = nums[i];
		}
		else if (nums[i] >= max3)
		{
			max3 = nums[i];
		}
	}
	int a = max1*max2*max3;
	int b = max1*min1*min2;
	return a > b ? a : b;

}



int main()
{
	
	//vector<int> nums = { 4,-3, -2, -1,60 };
	//cout << maximumProduct1(nums);
	vector<int> nums = { 1,2,3 };
	cout << maximumProduct(nums);

	return 0;
}