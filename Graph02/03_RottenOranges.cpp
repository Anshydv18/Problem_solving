class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //seems like bfs 
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x =  it.first.first;
            int y = it.first.second;
            int time = it.second;
            ans=max(ans,time);
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row = x + drow[i];
                int col = y + dcol[i];
                if(row>=0 && row<n && col>=0  && col<m && !vis[row][col] && grid[row][col]==1){
                    q.push({{row,col},time+1});
                    grid[row][col]=2;
                    vis[row][col]=1;
                }
            }
        }
        for(auto p:grid){
            for(auto x:p) if(x==1) return -1;
        }
        return ans;
    }
};