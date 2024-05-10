class Solution {
    class DisjointSet{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUp(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUp(parent[u]);
    }

    void unionByRank(int u,int v){
        int parentu = findUp(u);
        int parentv = findUp(v);
        if(parentu==parentv) return;

        int ranku = rank[parentu];
        int rankv = rank[parentv];
        if(ranku>rankv){
            parent[parentv]=parentu;
        }
        else if(ranku<rankv){
            parent[parentu]=parentv;
        }
        else{
            parent[parentu]=parentv;
            rank[parentu]++;
        }
    }

    void unionBySize(int u,int v){
        int parentu = findUp(u);
        int parentv = findUp(v);
        if(parentu==parentv) return;
        if(size[parentu]<size[parentv]){
            parent[parentu]=parentv;
            size[parentv]+=size[parentu];
        }
        else{
            parent[parentv]=parentu;
            size[parentu]+=size[parentv];
        }
    }
};
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DisjointSet ds(n);
        vector<pair<int,pair<int,int>>>adj;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                adj.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        int ms=0;
        for(auto it:adj){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUp(u)!=ds.findUp(v)){
                ms+=w;
                ds.unionBySize(u,v);
            }
        }
        return ms;
    }
};