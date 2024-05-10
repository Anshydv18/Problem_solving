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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice(n);
        DisjointSet Bob(n);
        int cnt=0;
        sort(edges.begin(),edges.end(),[](vector<int>&a, vector<int>& b){return a[0]>b[0];});
        for(auto it:edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];
            
            if(type==3){
                if(Alice.findUp(u)!=Alice.findUp(v)){
                    Alice.unionBySize(u,v);
                }
                if(Bob.findUp(u)!=Bob.findUp(v)){
                    Bob.unionBySize(u,v);
                }
                else cnt++;
            }
            else if(type==2){
                if(Alice.findUp(u)!=Alice.findUp(v)){
                    Alice.unionBySize(u,v);
                }
                else cnt++;
            }
            else{
                if(Bob.findUp(u)!=Bob.findUp(v)){
                    Bob.unionBySize(u,v);
                }
                else cnt++;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(Alice.parent[i]==i) res++;
        }
        if(res>1) return -1;
        res=0;
        for(int i=0;i<n;i++){
            if(Bob.parent[i]==i) res++;
        }
        if(res>1) return -1;
        return cnt;
    }
};