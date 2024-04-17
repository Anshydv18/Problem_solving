class Solution {
    public:
    bool isvalid(int x,int y,vector<vector<int>> &grid)                
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size())return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> &grid)
    {
        if(vis[x][y])return;               
        vis[x][y]=true;
        int up,down,left,right;
        up=down=left=right=0;               
        if(grid[x][y]==1)
            left=right=1;
        else if(grid[x][y]==2)
            up=down=1;
        else if(grid[x][y]==3)
            left=down=1;
        else if(grid[x][y]==4)
            down=right=1;
        else if(grid[x][y]==5)
            left=up=1;
        else
            up=right=1;
        if(up)
        {
            int new_x=x-1,new_y=y;        
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==2||grid[new_x][new_y]==3||grid[new_x][new_y]==4)) 
                dfs(new_x,new_y,vis,grid);
        }
        if(down)
        {
            int new_x=x+1,new_y=y;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==2||grid[new_x][new_y]==5||grid[new_x][new_y]==6))
                dfs(new_x,new_y,vis,grid);
        }
        if(right)
        {
            int new_x=x,new_y=y+1;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==1||grid[new_x][new_y]==5||grid[new_x][new_y]==3))
                dfs(new_x,new_y,vis,grid);
        }
        if(left)
        {
            int new_x=x,new_y=y-1;
            if(isvalid(new_x,new_y,grid) && (grid[new_x][new_y]==1||grid[new_x][new_y]==4||grid[new_x][new_y]==6))
                dfs(new_x,new_y,vis,grid);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return false;
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));           
        dfs(0,0,vis,grid);                                          
        return vis[n-1][m-1];                                       
      }
};