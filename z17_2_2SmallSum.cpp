#include<iostream>
using namespace std;


//1.合并两个有序数组
void MergeSortedArray(int *a, int m, int *b, int n)
{
	int i_new = m + n - 1;
	int i_a = m - 1, i_b = n - 1;
	while (i_a >= 0 && i_b >= 0)
	{
		if (a[i_a] >= b[i_b])
		{
			a[i_new--] = a[i_a--];
		}
		else
		{
			a[i_new--] = b[i_b--];
		}
	}
	while (i_a >= 0)
	{
		a[i_new--] = a[i_a--];
	}
	while (i_b >= 0)
	{
		a[i_new--] = b[i_b--];
	}
}


//2.归并排序

// 合并两个已排序子序列
void Merge(int* arr,int low,int mid,int high,int *temp)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

		}
	}
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= high)
	{
		temp[k++] = arr[j++];
	}
	for (i = 0; i < k; i++)
	{
		arr[low + i] = temp[i];
	}

}

//递归分解
void MergeSort(int *arr, int low, int high, int *temp)
{
	if (low < high)
	{
		int mid = low + ((high - low) >> 1);
		MergeSort(arr, low, mid, temp);
		MergeSort(arr, mid + 1, high, temp);
		Merge(arr, low, mid, high, temp);
	}
}

void Sort(int *arr, int n)
{
	int *temp = new int[n];
	MergeSort(arr, 0, n - 1, temp);
	delete[] temp;
}

/*测试代码
int a[10] = { 3,1,2,5,4,6};
Sort(a, 6);
for (int i = 0; i < 6; i++)
{
cout << a[i] << '\t';
}
*/

// 3. 数组小和
//利用归并排序的思路，合并过程中，统计s[i]之前小于等于s[i]的数的和。
int merge(int *arr, int low, int mid, int high,int *temp)
{
	int i = low, j = mid + 1;
	int k = 0;
	int SmallSum = 0;

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
		{
			SmallSum += arr[i] * (high - j + 1);
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	for (; ((i <= mid) || (j <= high)); i++, j++)
	{
		temp[k++] = i > mid ? arr[j] : arr[i];
	}
	for (i = 0; i < k; i++)
	{
		arr[low + i] = temp[i];
	}
	
	return SmallSum;
}

int mergesort(int *arr, int low, int high, int *temp)
{
	if (low == high)
	{
		return 0;
	}
	if (low < high)
	{
		int mid = low + ((high - low) >> 1);
		int s1 = mergesort(arr, low, mid, temp);
		int s2 = mergesort(arr, mid + 1, high, temp);
		int s3 = merge(arr, low, mid, high, temp);
		return s1 + s2 + s3;
	}

}

int sort(int *arr, int n)
{
	if (arr == NULL || n <= 0)
		return 0;
	int * temp = new int[n];
	int Sum = mergesort(arr, 0, n - 1, temp);
	delete[] temp;
	return Sum;
}

int main()
{

	int a[10] = { 3, 1, 2, 5, 4, 6 };
	cout << sort(a, 6)<<endl;
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << '\t';
	}
	return 0;
}