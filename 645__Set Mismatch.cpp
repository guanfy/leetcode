#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
	vector<int> res;
	sort(nums.begin(), nums.end());
	int i = 1, j = nums.size();
	while (nums[i-1] == i)
	{
		i++;
	}
	while (nums[j-1] == j)
	{
		j--;
	}
	if (nums[i-1] > i && nums[j-1] > j)
	{
		res.push_back(nums[j-1]);
		res.push_back(i);
	}
	else if (nums[i-1] < i && nums[j-1] < j)
	{
		res.push_back(nums[i-1]);
		res.push_back(j);
	}
	return res;
}
int main()
{
	vector<int> v = { 2, 2};
	vector<int> r;
	r = findErrorNums(v);
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << endl;
	}
	return 0;
}