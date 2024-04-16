class Solution {
    void dfs(int row,int col,vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col]=1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int r = row + drow[i];
            int c = col + dcol[i]; 
            if((r>=0 && r<grid.size()) && ( c>=0 && c<grid[0].size()) && !vis[r][c]  && grid[r][c]=='O') dfs(r,c,grid,vis);
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O') dfs(i,0,grid,vis);
            if(!vis[i][m-1] && grid[i][m-1]=='O') dfs(i,m-1,grid,vis);
        }

        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]=='O') dfs(0,i,grid,vis);
            if(!vis[n-1][i] && grid[n-1][i]=='O') dfs(n-1,i,grid,vis); 
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) grid[i][j]='O';
                else grid[i][j]='X';
            }
        }

    }
};