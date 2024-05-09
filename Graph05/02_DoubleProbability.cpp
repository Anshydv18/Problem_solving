class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>ds(n,0.0);
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0],v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        ds[start_node]=1.0;
        queue<pair<double,int>>q;
        q.push({1.0,start_node});
        while(!q.empty()){
            double prob = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto x:adj[node]){
                int nnode = x.first;
                double pprob = x.second;
                double ress = pprob*prob;
                if(ress>ds[nnode]){
                    ds[nnode]=ress;
                    q.push({ress,nnode});
                }
            }
        }
        return ds[end_node];
    }
};