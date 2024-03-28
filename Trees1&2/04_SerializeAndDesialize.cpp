/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
class Codec {
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           TreeNode* node = q.front(); q.pop();
           if(!node) res+="#,";
           else res+=(to_string(node->val)+',');
           if(node){
            q.push(node->left);
            q.push(node->right);
           }
        }
        return res;
    }

   
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            getline(ss,val,',');
            if(val=="#"){
                node->left=NULL;
            }
            else{
                node->left=new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss,val,',');
            if(val=="#"){
                node->right=NULL;
            }
            else{
                node->right=new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};