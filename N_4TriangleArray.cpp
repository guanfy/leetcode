#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����������
/*
���룺
	��һ�У� �����ε�����N
	����������
	7

	3   8

	8   1   0

	2   7   4   4

	4   5   2   6   5
������Ӷ������ױߵ�·����ʹ��·����������������֮�����

*/

//����1���ݹ�
/*
* D(r,j): ��ʾ��r�е�j����
* MaxSum(r,j): ��ʾ��D(r,j)���ױߵĸ���·���У����·������֮�͡�
* �ݹ���룺
* if(r == N)
*     return MaxSum(i,j) = D(r,j);
* else
*     return MaxSum(i,j) = max{MaxSum(i+1,j),MaxSum(i+1,j+1)} + D(r,j);
* ʱ�临�Ӷȣ�
*     o(2^N)
*ȱ�㣺���ڴ����ظ�����
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

//����2:�ݹ��Ͷ�̬�滮
/*
* ��¼ÿһ�������MaxSum[i][j],�´�ʹ��ʱֱ��ȡ��
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
	//1.�ݹ����,�����30. Time Limit Exceeded
	
	/*
	int i, j;
	cout << "������������������" << endl;
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

	// 2.��̬�滮
	/*
	int i, j;
	cout << "������������������" << endl;
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

	// ����3: ���ƶ�̬�滮
	int i, j;
	cout << "������������������" << endl;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> D[i][j];
		}
	}
	maxSum = D[N]; //ָ���N��
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