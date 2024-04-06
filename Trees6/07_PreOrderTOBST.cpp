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
    TreeNode* solve(vector<int>&ds,int low,int high){
        if(low>high) return NULL;
        TreeNode*  root = new TreeNode(ds[low]);
        int i;
        for(i=low+1;i<=high;i++){
            if(ds[low]<ds[i])break;
        }
        root->left = solve(ds,low+1,i-1);
        root->right= solve(ds,i,high);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& ds) {
        return solve(ds,0,ds.size()-1);
    }
};