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
    private:
    bool leaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    void solve(TreeNode* root,string s,vector<string>& ds){
        if(leaf(root)){
            ds.push_back(s);
            return;
        }
       
       if(root->left) solve(root->left,s+"->"+(to_string(root->left->val)),ds);
       if(root->right) solve(root->right,s+"->"+(to_string(root->right->val)),ds);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ds;
        if(!root) return {};
        string s = to_string(root->val);
        solve(root,s,ds);
        return ds;
    }
};