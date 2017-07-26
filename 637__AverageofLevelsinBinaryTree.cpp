#include<map>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

vector<double> averageOfLevels(TreeNode* root) {

	// ʱ�临�Ӷȣ�O(n),�ռ临�Ӷȣ�O(m)
	vector<double> res;
	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		int n = que.size();
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			TreeNode *pNode = que.front();
			if (pNode->left)
			{
				que.push(pNode->left);
			}
			if (pNode->right)
			{
				que.push(pNode->right);
			}
			sum += que.front()->val;
			que.pop();
		}
		res.push_back(sum / n);
	}
	return res;
}