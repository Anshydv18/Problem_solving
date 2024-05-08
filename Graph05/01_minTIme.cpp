class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
      //  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      queue<pair<int,int>>q;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        q.push({0,0});
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        while(!q.empty()){
            int node = q.front().second;
            int time = q.front().first;
            q.pop();

            if(disappear[node]<=time || dist[node]<time) continue;

            for(auto it:adj[node]){
                int ntime = it.second;
                int nnode = it.first;
                if(time+ntime<dist[nnode]){
                    int nettime = time + ntime;
                    if(nettime<disappear[nnode]){
                        dist[nnode]=nettime;
                        q.push({nettime,nnode});
                    }

                }
            }
        }
        for(auto &x:dist) if(x==INT_MAX) x=-1;
        return dist;
    }
};