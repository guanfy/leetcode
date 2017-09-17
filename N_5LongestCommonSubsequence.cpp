#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int LongestCommonSubsequence(string A, int n, string B, int m)
{
	vector<vector<int> >c(n+1,vector<int>(m+1,0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i-1] == B[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}

	vector<int> res(c[n][m], 0);
	int k = c[n][m] - 1;
	for (int i = n, j = m; i > 0 && j > 0;)
	{
		if (A[i-1] == B[j-1])
		{
			res[k--] = A[i-1];
			i--;
			j--;
		}
		else
		{
			c[i][j - 1] >= c[i - 1][j] ? j-- : i--;
		}
	}

	for (int i = 0; i < c[n][m]; i++)
		cout << char(res[i]) << '\t';
	cout << endl;
	return c[n][m];
}



//int main()
//{
//	string a = "13456778";
//	string b = "357486782";
//
//	cout << LongestCommonSubsequence(a, 8, b, 9)<<endl;
//	string a1 = "zynnqufc";
//	string b1 = "ddbauhkw";
//	cout << LongestCommonSubsequence(a1, 8, b1, 8) << endl;
//
//	return 0;
//}