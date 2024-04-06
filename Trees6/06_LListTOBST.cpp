/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        int mid = low+(high-low)/2;
        TreeNode* root =  new TreeNode(ds[mid]);
        root->left = solve(ds,low,mid-1);
        root->right = solve(ds,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ds;
        while(head!=NULL){
            ds.push_back(head->val);
            head=head->next;
        }
        return solve(ds,0,ds.size()-1);
    }
};