#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode *cur = root;
	while (cur)
	{

		if (cur->val < p->val && cur->val < q->val)
		{
			cur = cur->right;
		}
		else if (cur->val > p->val && cur->val > q->val)
		{
			cur = cur->left;
		}
		else
			return cur;
	}
}

//void dfs(vector<TreeNode*> cur, TreeNode*root, TreeNode *p, TreeNode *q, vector<TreeNode*> &Apath, vector<TreeNode*> &Bpath)
//{
//	cur.push_back(root);
//	if (root == p)
//	{
//		Apath = cur;
//	}
//	if (root == q)
//	{
//		Bpath = cur;
//	}
//	if (root->left)
//	{
//		dfs(cur, root->left, p, q, Apath, Bpath);
//	}
//	if (root->right)
//	{
//		dfs(cur, root->right, p, q, Apath, Bpath);
//	}
//}
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//	vector<TreeNode*> Apath;
//	vector<TreeNode*> Bpath;
//	vector<TreeNode*> cur;
//
//	dfs(cur, root, p, q, Apath, Bpath);
//	TreeNode* ret = root;
//	for (int i = 0; i < min(Apath.size(), Bpath.size()); i++)
//	{
//		if (Apath[i] == Bpath[i])
//		{
//			ret = Apath[i];
//		}
//		else
//			break;
//	}
//	return ret;
//}




/*

const int MAX = 1000;

int father[MAX],query[MAX][MAX],son[MAX][MAX],sum[MAX];
bool vis[MAX],hasroot[MAX];

int find(int x) //find x 的祖先节点
{
	//return father[x] == x? x:father[x] = find(father[x]);
	int r = x;
	while (r != father[r])
	{
		r = father[r];
	}
	return r;
}

void Tarjan(int u)
{
	vis[u] = true;
	int i, v;
	for (i = 1; i <= query[u][0]; i++)
	{
		v = query[u][i];
		if (vis[v]) ++sum[find(v)];
	}
	for (i = 1; i < son[u][0]; i++)
	{
		v = son[u][i];
		if (!vis[v])
		{
			Tarjan(v);
			father[v] = u;
		}
	}
}
inline void add(int a, int b)
{
	++query[a][0]; //用query[节点a][0]表示查询LCA(a,?)的个数
	query[a][query[a][0]] = b; //记录这一查询LCA(a,b)
}

int main()
{
	int n, i, j, k, Q;
	while (~scanf("%d", &n))
	{
		memset(vis, 0, sizeof(vis));
		memset(sum, 0, sizeof(sum));
		memset(hasroot, 0, sizeof(hasroot));
		for (i = 1; i <= n; ++i)
		{
			father[i] = i, query[i][0] = 0;
			scanf("%d", &j);
			while (getchar() != '(');
     		scanf("%d", &son[j][0]);///注意，我们用son[节点编号][0]表示儿子个数
			while (getchar() != ')');
			for (k = 1; k <= son[j][0]; ++k)
			{
				scanf("%d", &son[j][k]);///记录此节点的儿子节点编号
				hasroot[son[j][k]] = true;
			}
		}
		scanf("%d", &Q);
		while (Q--)
		{
			while (getchar() != '(');
			scanf("%d%d", &i, &j);
			while (getchar() != ')');
			add(i, j), add(j, i);///双向添加查询
		}
		for (i = 1; i <= n; ++i)
		if (!hasroot[i]) { Tarjan(i); break; }///从根节点进入
		for (i = 1; i <= n; ++i)
		if (sum[i]) printf("%d:%d\n", i, sum[i]);
	}
	return 0;
}
*/