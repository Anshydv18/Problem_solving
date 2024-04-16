//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>res(n,vector<int>(m,-1));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    //lets traverse over the array and try to put in the queue data structure for BFS
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]){
	                res[i][j]=0;
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    //now i have stored all the values in the queue which is one
	    while(!q.empty()){
	        auto it = q.front(); q.pop();
	        int x = it.first.first;
	        int y = it.first.second;
	        int t = it.second;
	        int drow[] = {-1,0,1,0};
	        int dcol[] = {0,-1,0,1};
	        for(int i=0;i<4;i++){
	            int row = x+drow[i];
	            int col = y+dcol[i];
	            if((row>=0 && row<n) && (col>=0 && col<m) && !vis[row][col]){
	                res[row][col]=t+1;
	                vis[row][col]=1;
	                q.push({{row,col},t+1});
	            }
	        }
	    }
	   return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends