class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto x:flights){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
      //  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        queue<pair<int,pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,{k+1,src}});
        while(!pq.empty()){
            
            auto it = pq.front(); pq.pop();
            int cost = it.first;
            int rem = it.second.first;
            if(rem==0) continue;
            int node = it.second.second;
            cout<<cost<<" "<<rem<<" "<<node<<endl;
            //if(node==dst) return cost;
            for(auto x:adj[node]){
                int nNode =  x.first;
                int ncost = x.second;
                if(ncost+cost<dist[nNode]){
                    dist[nNode]=ncost+cost;
                    cout<<nNode<<" "<<dist[nNode]<<endl;
                    pq.push({ncost+cost,{rem-1,nNode}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};