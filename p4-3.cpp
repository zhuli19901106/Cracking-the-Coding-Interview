// 4.3 Convert sorted unique array to height-balanced binary search tree.
#include <algorithm>
#include <cstdio>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int _val = 0): val(_val), left(nullptr), right(nullptr) {};
};

void consructBSTFromSortedArray(vector<int> &v, int left, int right, TreeNode *&root)
{
	if (left > right) {
		root = nullptr;
	} else {
		int mid = (left + right + 1) / 2;
		root = new TreeNode(v[mid]);
		consructBSTFromSortedArray(v, left, mid - 1, root->left);
		consructBSTFromSortedArray(v, mid + 1, right, root->right);
	}
}

void preorderTraversal(TreeNode *root)
{
	if (root == nullptr) {
		printf("# ");
	} else {
		printf("%d ", root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void clearBinaryTree(TreeNode *&root)
{
	if (root == nullptr) {
		return;
	} else {
		clearBinaryTree(root->left);
		clearBinaryTree(root->right);
		delete root;
		root = nullptr;
	}
}

int main()
{
	TreeNode *root;
	unordered_map<TreeNode *, int> heights;
	int i, n, val;
	vector<int> v;
	
	while (scanf("%d", &n) == 1 && n > 0) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			v.push_back(val);
		}
		
		consructBSTFromSortedArray(v, 0, n - 1, root);
		preorderTraversal(root);
		printf("\n");
		
		v.clear();
		clearBinaryTree(root);
	}
	
	return 0;
}