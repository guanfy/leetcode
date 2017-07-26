#include<iostream>
#include <vector>
using namespace std;

//·½·¨1£ºo(n),o(n)
class NumArray {
public:
	NumArray(vector<int> nums) {
		for (int i = 0; i<nums.size(); i++)
		{
			val.push_back(nums[i]);
		}
	}

	inline int sumRange(int i, int j) {
		int sum = 0;
		while (i != j + 1)
		{
			sum += val[i++];
		}
		return sum;
	}

	vector<int> val;
};
