#include<iostream>
#include<string>

using namespace std;

string addBinary(string a, string b) {
	if (a.empty())
		return b;
	if (b.empty())
		return a;

	int i = a.size() - 1;
	int j = b.size() - 1;
	int takeover = 0;
	string sum;

	for (; i >= 0 && j >= 0; i--, j--)
	{
		int n_sum = a[i] - '0' + b[j] - '0' + takeover;
		sum.push_back(n_sum % 2 + '0');
		takeover = n_sum / 2;
	}

	while (i < 0)
	{
		if (j < 0)
		{
			break;
		}
		else
		{
			int n_sum = b[j] - '0' + takeover;
			sum.push_back(n_sum % 2 + '0');
			takeover = n_sum / 2;
			j--;
		}
	}

	while (j < 0)
	{
		if (i < 0)
		{
			break;
		}
		else
		{
			int n_sum = a[i] - '0' + takeover;
			sum.push_back(n_sum % 2 + '0');
			takeover = n_sum / 2;
			i--;
		}
	}
	if (takeover != 0)
	{
		sum.push_back(takeover+'0');
	}
	reverse(sum.begin(),sum.end());
	
	return sum;
}

int main()
{ 
	string a = "111";
	string b = "111";

	cout << addBinary(a, b);
	
	return 0;
}