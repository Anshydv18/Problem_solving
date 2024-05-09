class Solution {
    void solve(int node,vector<int>& dist,unordered_map<int,vector<pair<int,int>>>& adj){
        queue<pair<int,int>>q;
        q.push({0,node});
        dist[node]=0;
        while(!q.empty()){
            int nd = q.front().second;
            int dis = q.front().first;
            q.pop();
            for(auto x:adj[nd]){
                int nnode = x.first;
                int ndis = x.second;
                if(ndis+dis<dist[nnode]){
                    dist[nnode]=ndis+dis;
                    q.push({dist[nnode],nnode});
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0],v = edges[i][1],w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans=INT_MAX,res=0;
        for(int i=0;i<n;i++){
            vector<int>dist(n,INT_MAX);
            solve(i,dist,adj);
            int cnt=0;
            for(auto x:dist){
                if(x<=distanceThreshold) cnt++;
            }
           
            if(ans>=cnt){
                ans=cnt;
                res=i;
            }
        }
        return res;
    }
};