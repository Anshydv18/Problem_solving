int heightOfBinaryTree(TreeNode<int> *root)
{
	if(!root) return 0;
    return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right))+1;
}