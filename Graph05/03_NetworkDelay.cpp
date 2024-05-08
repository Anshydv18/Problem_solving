class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto x:times){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});

        while(!q.empty()){
            int time = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto x:adj[node]){

                int nNode = x.first;
                int ttime = x.second;
                if(time+ttime<dist[nNode]){
                    dist[nNode]=time+ttime;
                    q.push({time+ttime,nNode});
                }
            }
        }
        for(auto x:dist) cout<<x<<" ";
        int maxx = *max_element(dist.begin(),dist.end());
        return maxx==INT_MAX?-1:maxx;
    }
};