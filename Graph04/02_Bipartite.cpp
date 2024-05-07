class Solution {
    bool solve(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& color){
        
        queue<pair<int,int>>q;
       q.push({node,0});
       vis[node]=1;
       color[node]=0;
       while(!q.empty()){
        int node = q.front().first;
        int col = q.front().second;
        q.pop();
        for(auto x:graph[node]){
            if(!vis[x]){
                vis[x]=1;
                q.push({x,!col});
                color[x]=!col;
            }
            else if(vis[x]){
               
                if(!color[x]!=col) return false;
            }
        }
       }
       return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       //making a queue of color with nodes
       vector<int>vis(n,0),color(n,-1);
       for(int i=0;i<n;i++){
        if(!vis[i]){
             cout<<i<<" "<<endl;
            if(!solve(i,graph,vis,color)) return false;
           
        }
       }
       return true;
    }
};