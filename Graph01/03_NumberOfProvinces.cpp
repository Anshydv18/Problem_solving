class Solution {
    void dfs(int node,vector<int>& vis, unordered_map<int,vector<int>>& adj){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]) dfs(x,vis,adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& ds) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<ds.size();i++){
            for(int j=0;j<ds.size();j++){
                if(ds[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(ds.size(),0);
        for(int i=0;i<ds.size();i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};