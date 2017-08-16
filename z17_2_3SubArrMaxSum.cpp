#include<iostream>
using namespace std;

int SubArrMaxSum(int *arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		return INT_MIN;
	}
	int max_sum = INT_MIN;
	int sum = 0;
	int left = 0;
	int left_cur = 0;
	int right = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (max_sum <= sum)
		{
			max_sum = sum;
			left = left_cur;
			right = i;
		}
		if (sum < 0)
		{
			sum = 0;
			left_cur = i + 1;
		}
	}
	cout << left << '\t' << right << '\t';
	return max_sum;
}


int main()
{
	int a[10] = { 1, -2, 3, 5, -2, 6, -1 };
	cout << SubArrMaxSum(a, 7)<<endl;

	int b[10] = { -1, -2, -3, -4, -5 };
	cout << SubArrMaxSum(b, 5) << endl;

	int c[10] = { 0, 0, 0, 0, 0, 0,0 };
	cout << SubArrMaxSum(c, 7) << endl;

	return 0;
}