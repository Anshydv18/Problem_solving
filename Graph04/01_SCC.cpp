//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node,int vis[],vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]) dfs(x,vis,adj,st);
        }
        st.push(node);
    }
    private:
    void dff(int node,int vis[],vector<int> adjT[]){
        vis[node]=1;
        for(auto x:adjT[node]){
            if(!vis[x]) dff(x,vis,adjT);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       stack<int>st;
       int vis[V]={0};
       for(int i=0;i<V;i++){
           if(!vis[i]) dfs(i,vis,adj,st);
       }
       vector<int> adjT[V];
       for(int i=0;i<V;i++){
           vis[i]=0;
           for(auto x:adj[i]){
               adjT[x].push_back(i);
           }
       }
       
       int scc =0;
       while(!st.empty()){
           int node = st.top();
           
           st.pop();
           if(!vis[node]){ dff(node,vis,adjT);
               scc++;
           }
           
       }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends