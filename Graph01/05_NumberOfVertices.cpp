class Solution {

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ds;
        unordered_map<int,bool>adj;
        for(auto x:edges){
            adj[x[1]]=true;
        }
        for(int i=0;i<n;i++){
            if(adj[i]==false){
                ds.push_back(i);
            }
        }
        return ds;
    }
};