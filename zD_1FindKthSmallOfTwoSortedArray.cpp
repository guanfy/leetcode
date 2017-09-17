#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findKthSmall(int *nums1, int m, int *nums2, int n, int k)
{
	if (m + n < k || k == 0)
		return -1;
	
		if (m > n)
			return findKthSmall(nums2, n, nums1, m, k);
		if (m == 0 && n >= k)
			return nums2[k - 1];
		if (k == 1)
			return min(nums1[0], nums2[0]);
		int p1 = min(k / 2, m);
		int p2 = k - p1;
		if (nums1[p1-1] < nums2[p2-1])
			return findKthSmall(nums1 + p1, m - p1, nums2, n, k - p1);
		else if (nums1[p1-1] > nums2[p2-1])
			return findKthSmall(nums1, m, nums2 + p2, n - p2, k - p2);
		else
			return nums1[p1 - 1];
}

//int main()
//{
//	int a[10] = { 1, 3, 5, 7, 9 };
//	int b[15] = { 2, 4 };
//
//	cout<<findKthSmall(a, 5, b, 2,1 )<<endl;
//	return 0;
//}