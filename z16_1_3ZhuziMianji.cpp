#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxArea(vector<int> &nums)
{
	if (nums.size() <= 2)
		return 0;
	int L = 0;
	int R = nums.size() - 1;
	int maxA = 0;

	while (L <= R)
	{
		int min_v = min(nums[L], nums[R]);
		int Area = min_v * (R - L - 1);
		min_v == nums[L] ? L++ : R--;
		maxA = max(maxA, Area);
	}
	return maxA;
}
//int main()
//{
//	vector<int> v = { 3, 4, 2, 5 };
//	cout << MaxArea(v)<<endl;
//
//	return 0;
//}