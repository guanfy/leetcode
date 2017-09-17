#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//方法1：双头指针，找第k个元素。不适用于较大K的
//int findKth(vector<int>& nums1, vector<int>& nums2, int k)
//{
//	int i = 0, j = 0;
//	int count = 0;
//	int res;
//	while (i < nums1.size() && j < nums2.size() && count < k )
//	{
//		res = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
//		count++;
//	}
//	while (i < nums1.size() && count < k)
//	{
//		res = nums1[i++];
//		count++;
//	}
//	while (j < nums2.size() && count < k)
//	{
//		res = nums2[j++];
//		count++;
//	}
//	if (count == k)
//		return res;
//	
//}
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int len1 = nums1.size();
//	int len2 = nums2.size();
//	int total = len1 + len2;
//	if (total % 2 == 0)
//		return (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2.0;
//	else
//		return findKth(nums1, nums2, total / 2 + 1);
//}

//方法2：查找第K个元素，下标为K-1; p + q = k-1;二分法

//double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int len1, int start2, int len2, int k)
//{
//	if (len1 > len2)
//	{
//		return findKth(nums2, nums1, start2, len2, start1, len1, k);
//	}
//	if (len1 == 0)
//	{
//		return nums2[start2 + k - 1];
//	}
//	if (k == 1)
//	{
//		return min(nums1[start1], nums2[start2]);
//	}
//	int p1 = min(k / 2, len1);
//	int p2 = k - p1;
//
//	if (nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1])
//	{
//		return findKth(nums1, nums2, start1 + p1, len1 - p1, start2, len2, k - p1);
//	}
//	else if (nums1[start1 + p1 - 1] > nums2[start2 + p2 - 1])
//	{
//		return findKth(nums1, nums2, start1, len1, start2 + p2, len2 - p2, k - p2);
//	}
//	else
//	{
//		return nums1[start1 + p1 - 1];
//	}
//}
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	int len1 = nums1.size();
//	int len2 = nums2.size();
//	int total = len1 + len2;
//	if (total % 2 == 0)
//	{
//		return (findKth(nums1, nums2, 0, len1, 0, len2, total / 2) + findKth(nums1, nums2, 0, len1, 0, len2, total / 2 + 1)) / 2.0;
//	}
//	else
//	{
//		return(findKth(nums1, nums2, 0, len1, 0, len2, total / 2 + 1));
//	}
//
//}

//方法3： 与方法2思路相同，但时间较快
double findKth(int *v1,int len1,int *v2,int len2,int k)
{
	if (len1 > len2)
		return findKth(v2, len2, v1, len1, k);
	if (len1 == 0)
		return v2[k - 1];
	if (k == 1)
		return min(v1[0], v2[0]);
	int p1 = min(k / 2, len1);
	int p2 = k - p1;
	if (v1[p1 - 1] < v2[p2 - 1])
	{
		return findKth(v1 + p1, len1 - p1, v2, len2, k - p1);
	}
	else if (v1[p1 - 1] > v2[p2 - 1])
	{
		return findKth(v1, len1, v2 + p2, len2 - p2, k - p2);
	}
	else
		return v1[p1 - 1];

}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	int *v1 = nums1.data();
	int *v2 = nums2.data();
	int len = len1 + len2;
	if (len & 0x1)
	{
		return findKth(v1,len1,v2,len2,len / 2 + 1);
	}
	else
	{
		return (findKth(v1, len1, v2, len2, len / 2) + findKth(v1, len1, v2, len2, len / 2 + 1)) / 2.0;
	}

}
int main()
{
	vector<int> v1 = { 1, 2, 3, 5,6};
	vector<int> v2 = { 4, 7, 9 };

	cout << findMedianSortedArrays(v1, v2)<<endl;
	return 0;
}