class Solution {
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        //if() return;
        vis[row][col]=1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int r = row+drow[i];
            int c = col+dcol[i];
            if((r>=0 && r<grid.size()) && (c>=0 && c<grid[0].size()) &&!vis[r][c] && grid[r][c]=='1') dfs(r,c,grid,vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++; 
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};