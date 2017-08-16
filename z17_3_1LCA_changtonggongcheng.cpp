#include<iostream>
using namespace std;
const int MAXN = 1000;
int Fa[MAXN];

int find(int x)
{
	return Fa[x] == x ? x : Fa[x] = find(Fa[x]);
}

void merge(int a, int b)
{
	int fa = find(a), fb = find(b);
	if (fa != fb)
	{
		Fa[fa] = fb;
	}
}


int main()
{
	int n, m;

	while (cin >> n)
	{
		while (cin >> m)
		{
			for (int i = 1; i <= n; i++)
			{
				Fa[i] = i;
			}
			int a, b;
			while (m--)
			{
				cin >> a >> b;
				merge(a, b);
			}
			int res = 0;
			for (int i = 1; i <= n; i++)
			{
				if (Fa[i] == i) res++;
			}

			cout << res-1;
		}
	}

	return 0;
}