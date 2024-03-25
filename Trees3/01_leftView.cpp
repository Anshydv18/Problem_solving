#include<bits/stdc++.h>
vector<int> printLeftView(BinaryTreeNode<int>* root) {
  vector<int>ds;
  if(!root) return {};
  queue<pair<BinaryTreeNode<int>*,int>>q;
  q.push({root,1});
  while(!q.empty()){
      BinaryTreeNode<int>* node = q.front().first;
      int level = q.front().second;
      q.pop();
      if(ds.size()<level) ds.push_back(node->data);
      if(node->left) q.push({node->left,level+1});
      if(node->right) q.push({node->right,level+1});
  }
  return ds;
}