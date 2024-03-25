/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
 vector<int> res;
 
 void f(TreeNode* A, int b ,vector<int>& ds){
     if(A==NULL) return;
     if(A->val==b){
         res=ds;
         return;
     }
    if(A->left) {
        ds.push_back(A->left->val);
        f(A->left,b,ds);
        ds.pop_back();
    }
    if(A->right) {
        ds.push_back(A->right->val);
        f(A->right,b,ds);
        ds.pop_back();
    }
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    if(!A) return {};
    vector<int>ds;
    ds.push_back(A->val);
     f(A,B,ds);
     return res;
   
}