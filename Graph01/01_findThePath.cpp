class Solution {
    int vis[1000000];
    // bool check(int source,int destination,unordered_map<int,vector<int>>& adj){
    //     if(source==destination) return true;
    //     vis[source]=1;
    //     bool ans=false;
    //     for(auto x:adj[source]){
    //         if(x==destination) return true;
    //         if(!vis[x]){
    //             ans=ans||check(x,destination,adj);
    //             if(ans) return true;
    //         }
    //     }
    //     return ans;
    // }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //lets make the adjaceny list for every node
        memset(vis,sizeof(vis),0);
        unordered_map<int,vector<int>>adj;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        if(source==destination) return true;
        q.push(source);
        while(!q.empty()){
            int node = q.front(); q.pop();
            vis[node]=1;
            for(auto x:adj[node]){
                if(x==destination) return true;
                if(!vis[x]) q.push(x);
            }
        }
        return false;
    }
};