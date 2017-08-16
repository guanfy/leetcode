#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
	if (root == nullptr || root == p || root == q){
		return root;
	}
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	if (left == nullptr) return right;
	if (right == nullptr) return left;
}

int getLCA(int a, int b)
{
	int fmin = a <= b ? a : b;
	int fmax = a >= b ? a : b;
	while (fmin != fmax)
	{
		if (fmin < (fmax >> 1))
		{
			fmin = fmin >> 1;
		}
		fmax = fmax >> 1;
	}
	return fmin;
}

int getLCA_1(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a >> 1;
		}
		else
		{
			b = b >> 1;
		}
	}
	return a;
}

int main()
{
	int a = 10;
	if (a >> 1 == 5)
		a = a >> 1;
		cout << a << endl;
	return 0;
}