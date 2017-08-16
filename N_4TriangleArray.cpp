#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//数字三角形
/*
输入：
	第一行： 三角形的行数N
	输入三角形
	7

	3   8

	8   1   0

	2   7   4   4

	4   5   2   6   5
输出：从顶部到底边的路径，使得路径上所经过的数字之和最大。

*/

//方法1：递归
/*
* D(r,j): 表示第r行第j个数
* MaxSum(r,j): 表示从D(r,j)到底边的各条路径中，最佳路径数字之和。
* 递归代码：
* if(r == N)
*     return MaxSum(i,j) = D(r,j);
* else
*     return MaxSum(i,j) = max{MaxSum(i+1,j),MaxSum(i+1,j+1)} + D(r,j);
* 时间复杂度：
*     o(2^N)
*缺点：存在大量重复计算
*/
#define MAX 101
int D[MAX][MAX];
int N;
int MaxSum[MAX][MAX];
int *maxSum;

int MaxSumofTrianglePath_2_n(int i, int j)
{
	if (i == N)
		return D[i][j];
	else
		return max(MaxSumofTrianglePath_2_n(i + 1, j), MaxSumofTrianglePath_2_n(i + 1, j + 1)) + D[i][j];
}

//方法2:递归型动态规划
/*
* 记录每一次算出的MaxSum[i][j],下次使用时直接取出
*/
int MaxSumofTrianglePath_n_2(int i, int j)
{
	if (MaxSum[i][j] != -1)
		return MaxSum[i][j];
	if (i == N)
		return D[i][j];
	else
	{
		return max(MaxSumofTrianglePath_n_2(i + 1, j), MaxSumofTrianglePath_n_2(i + 1, j + 1)) + D[i][j];
	}
	return MaxSum[i][j];
}

int main()
{
	//1.递归测试,输出：30. Time Limit Exceeded
	
	/*
	int i, j;
	cout << "请输入三角形行数：" << endl;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> D[i][j];
			MaxSum[i][j] = -1;
		}
	}
	cout << MaxSumofTrianglePath_2_n(1, 1) << endl;
	*/

	// 2.动态规划
	/*
	int i, j;
	cout << "请输入三角形行数：" << endl;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> D[i][j];
			MaxSum[i][j] = -1;
		}
	}
	cout << MaxSumofTrianglePath_n_2(1, 1) << endl;
	*/

	// 方法3: 递推动态规划
	int i, j;
	cout << "请输入三角形行数：" << endl;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
	}
	maxSum = D[N]; //指向第N行
	for (i = N - 1; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
		}
	}
	cout << maxSum[1] << endl;



	return 0;
}