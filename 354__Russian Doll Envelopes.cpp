#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	int res = 0;
	int n = envelopes.size();
	vector<int> dp(n, 1);
	//按照信封的宽度进行排序
	sort(envelopes.begin(), envelopes.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//长度宽度满足条件，利用动态规划递推式更新dp数组中对应的值,若后一个数组的两个数都大于前面数组，则更新。
			if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
				dp[i] = max(dp[i], dp[j + 1]);
		}
		res = max(res, dp[i]);
	}
	
	return res;
}

static bool cmp(const std::pair<int, int>a, const std::pair<int, int>b)
{
	return  a.first == b.first ? a.second > b.second:a.first < b.first;
}
int maxEnvelopes_n_logn(vector<pair<int, int>>& envelopes) {
	if (envelopes.size() == 0)
		return 0;
	sort(envelopes.begin(), envelopes.end(), cmp);
	vector<int> h;
	h.push_back(envelopes[0].second);
	int right = 0;
	int l = 0;
	int r = 0;
	int m = 0;
	for (int i = 1; i < envelopes.size(); i++)
	{
		if (envelopes[i].second > h[right])
		{
			h.push_back(envelopes[i].second);
			right = right + 1;
		}
		else
		{
			l = 0;
			r = right;
			while (l <= r)
			{
				m = (l + r) / 2;
				if (h[m] >= envelopes[i].second)
					r = m - 1;
				else
					l = m + 1;
			}
			h[l] = envelopes[i].second;
		}
	}

	return right + 1;
}



int  main()
{
	vector<pair<int, int>> vec;
	vec.push_back(make_pair<int, int>(1, 2));
	vec.push_back(make_pair<int, int>(3, 7));
	vec.push_back(make_pair<int, int>(4, 3));
	vec.push_back(make_pair<int, int>(5, 4));
	cout << maxEnvelopes_n_logn(vec)<<endl;

	//sort(vec.begin(), vec.end(),strict_weak_ordering);

	//vector<pair<int, int>>::iterator it = vec.begin(), end = vec.end();
	//for (; it != end; it++)
	//{
	//	cout << '(' << it->first << ',' << it->second << ')' << endl;
	//}
	return 0;
}