/* 1->First solution , getting it over the inordered traversal*/
void solve(Node* root,vector<int>&ds){
    if(!root) return;
    solve(root->left,ds);
    ds.push_back(root->data);
    solve(root->right,ds);
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    vector<int>ds;
    solve(root,ds);
    auto it = lower_bound(ds.begin(),ds.end(),input)-ds.begin();
    if(ds[it]==input) return input;
    if(it==ds.size() && ds[it]<input) return -1;
    return ds[it];
    // Your code here
}

/*2->solution  */