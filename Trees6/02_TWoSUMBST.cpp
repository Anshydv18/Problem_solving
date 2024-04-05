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
 void inorder(TreeNode* root,vector<int>& nums){
     if(!root) return;
     inorder(root->left,nums);
     nums.emplace_back(root->val);
     inorder(root->right,nums);
 }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        inorder(root,nums);
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]>k) j--;
            else if(nums[i]+nums[j]<k) i++;
            else return true;
        }
        return false;
    }
};