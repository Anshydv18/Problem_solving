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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>col;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                col.emplace_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.emplace_back(col);
        }
        int n = res.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int s = res[i].size();
            ans.emplace_back(res[i][s-1]);
        }
        return ans;
    }
};