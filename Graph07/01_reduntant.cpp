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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(1001);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUp(u)==ds.findUp(v)){
                return {u,v};
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        return {};
    }
};