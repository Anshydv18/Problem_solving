class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
     unordered_map<int,vector<int>>adj;
     vector<int>ind(n,0);
     for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        ind[edges[i][1]]++;
     }
     queue<int>q;
     vector<int>topo;
     for(int i=0;i<n;i++){
        if(ind[i]==0)q.push(i);
     }
     while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            ind[it]--;
            if(ind[it]==0) q.push(it);
        }
     }
     reverse(topo.begin(),topo.end());
     if(topo.size()==n) return topo;
     return {};
    }
};