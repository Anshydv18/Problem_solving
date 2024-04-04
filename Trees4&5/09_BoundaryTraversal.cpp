/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> ds;
bool isLeaf(TreeNode<int>* root){
    if(root->left==NULL && root->right==NULL) return true;
    return false;
}
void left(TreeNode<int>* root){
    TreeNode<int>* curr = root;
    ds.push_back(root->data);
    if(!curr->left) return;
    curr=curr->left;
    
    while(curr){
        if(!isLeaf(curr)) ds.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void bottom(TreeNode<int>* root){
    if(!root) return;
    if(isLeaf(root)){
        ds.push_back(root->data);
        return;
    }
    bottom(root->left);
    bottom(root->right);
}

void right(TreeNode<int>* root){
    TreeNode<int>* curr = root;
    vector<int>ans;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
   vector<int>arr;
    int i=0;
   for( ;i<ans.size() && i<ds.size();i++){
       if(ds[i]!=ans[i]) arr.push_back(ans[i]);
   }
   for(;i<ans.size();i++) arr.push_back(ans[i]);
   reverse(arr.begin(),arr.end());
   for(auto x:arr)ds.push_back(x);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	left(root);
    bottom(root);
    right(root);
    
    return ds;
}
