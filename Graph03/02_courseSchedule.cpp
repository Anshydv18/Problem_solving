class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int>ind(n,0);
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<edges.size();i++){
        auto x = edges[i];
        adj[x[0]].push_back(x[1]);
        ind[x[1]]++;
    }
    int cnt=0;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto x:adj[node]){
            ind[x]--;
            if(ind[x]==0) q.push(x);

        }
    }
    return cnt==n;
    }
};