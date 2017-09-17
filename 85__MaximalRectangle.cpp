#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
int maxRecFromBottom(vector<int> height)
{
	if (height.empty() || height.size() <= 0)
		return 0;
	int maxArea = 0; 
	stack<int> sta;
	
	for (int i = 0; i < height.size(); i++)
	{
		while (!sta.empty() && height[i] <= height[sta.top()])
		{
			int cur = sta.top();
			sta.pop();
			int left = sta.empty() ? -1 : sta.top();
			int curarea = (i - left - 1)*height[cur];
			maxArea = max(maxArea, curarea);
		}
		sta.push(i);
	}
	while (!sta.empty())
	{
		int cur = sta.top();
		sta.pop();
		int left = sta.empty() ? -1 : sta.top();
		int curarea = (height.size() - left - 1)*height[cur];
		maxArea = max(maxArea, curarea);
	}
	return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {

	if ( matrix.empty())
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> height(n, 0);
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '0')
			{
				height[j] = 0;
			}
			else
			{
				height[j] += 1;
			}
		}
		res = max(res, maxRecFromBottom(height));
	}
	return res;
}


//int main()
//{
//	vector<vector<char> > v = { { 1, 0, 1, 0, 0 }, { 1, 0, 1, 1, 1 }, { 1, 0, 1, 1, 1 }, {1,0,0,1,0} };
//	cout<<maximalRectangle(v);
//	return 0;
//}