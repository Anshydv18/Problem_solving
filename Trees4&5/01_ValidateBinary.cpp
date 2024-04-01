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
    void solve(TreeNode* root,vector<int>& res){
        if(!root) return;
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>res;
        solve(root,res);
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]) return false;
        }
        return true;
    }
};


//learned code from others solution, 
/*
1-> when we pass null in (int) it result it to zero
2->if we will pass int_min, it will fail on node value of INT_MIN

*/
class Solution {
    private:
    bool valid(TreeNode* root,int *left,int *right){
        if(!root) return true;
        if(right && root->val>=*right) return false;
        if(left && root->val<=*left) return false;
        return valid(root->left,left,&(root->val)) && valid(root->right,&(root->val),right);
    }
public:
    bool isValidBST(TreeNode* root) {
      return valid(root,NULL,NULL);
    }
};