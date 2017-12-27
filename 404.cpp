class Solution {
	bool isLeaf(TreeNode * root) {
		if(root==NULL)
			return 0;
		if(root->left==NULL&&root->right==NULL)
			return 1;
		return 0;
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if(root==NULL)
			return 0;
		if(isLeaf(root->left)) 
			return root->left->val+sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
	}
};
