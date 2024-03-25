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
    vector<string>ds;
    void path(TreeNode* root,int val,string &s){
        if(!root) return;
        if(root->val==val){
            ds.push_back(s);
            return;
        }
        if(root->left) {
            s.push_back('L');
            path(root->left,val,s);
            s.pop_back();
            }
        if(root->right){
            s.push_back('R');
            path(root->right,val,s);
            s.pop_back();
            }

    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root) return "";
        string s = "";
        path(root,startValue,s);
        path(root,destValue,s);
        string a = ds[0];
        string b = ds[1];
        
        int i=0;
        for(;i<a.length() || i<b.length();i++){
           if(i<a.length() && i<b.length()){ 
            if(a[i]==b[i]) continue;
            else{
                int size = a.length()-i;
                while(size--) s.push_back('U');
                while(i<b.length()) s+=b[i++];
                return s;
            }
            }
            else{
                if(i<a.length())  s+='U';
                else s+=b[i];
            }
        }
       return s;
    }
};