/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int leftNodes(TreeNode* root){
        if(!root) return 0;
        return leftNodes(root->left)+leftNodes(root->right)+1;
    }
    int solve(TreeNode* root,int k){
        if(!root) return 0;
        // if(k<=0) return root->val;
        int left = leftNodes(root->left);
        if(left+1==k) return root->val;
        if(left>=k) return solve(root->left,k);
        else return solve(root->right,k-(left+1));
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};