#include<iostream>
#include<algorithm>
using namespace std;

char arr[100][100];
char res[100][100];
int main()
{
	int n, m;
	int r_i = 0, r_j = 0;
	int left = 0, right = 0;
	int i_start = 0, i_end = 0;
	while (cin >> n && cin >> m)
	{
		left = m - 1;
		right = 0;
		i_start = n - 1;
		i_end = 0;
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
			i_start = min(i_start, i);
			i_end = max(i_end, i);
		}
		
		for (int i = i_start; i <= i_end; i++)
		{
			r_j = 0;
			for (int j = left; j <= right; j++)
			{
				res[r_i][r_j++] = arr[i][j];
			}
			r_i++;
		}
	}
	for (int i = 0; i < r_i; i++)
	{
		for (int j = 0; res[i][j] != '\0'; j++)
			cout << res[i][j];
		cout << endl;
	}

	return 0;
}
