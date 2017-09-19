#include<iostream>
#include<algorithm>
using namespace std;

char arr[100][100];
int main()
{
	int n, m;
	int left = 0, right = 0;
	while (cin >> n && cin >> m)
	{
		left = m - 1;
		right = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			int j = 0, k = m - 1;
			while (arr[i][j] == '.' && j < k)
			{
				j++;
			}
			if (j == k && arr[i][j] == '.')
				continue;
			while (arr[i][k] == '.' && k > j)
			{
				k--;
			}
			left = min(left, j);
			right = max(right, k);
		}
	}
	return 0;
}
