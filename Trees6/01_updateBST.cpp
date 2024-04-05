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
    int nodes(TreeNode* root){
        if(!root) return 0;
        return 1+nodes(root->left)+nodes(root->right);
    }
    void inOrder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    void update(TreeNode* &root,vector<int>&ans,int low,int high){
        if(low>high) return;
        if(!root) return;
        int left = nodes(root->left);
        root->val = ans[low+left];
        update(root->left,ans,low,low+left-1);
        update(root->right,ans,low+left+1,high);
    }
public:
    void recoverTree(TreeNode* root) {
       vector<int>ans;
       inOrder(root,ans);
       sort(ans.begin(),ans.end());
       update(root,ans,0,ans.size()-1);
        
    }
};