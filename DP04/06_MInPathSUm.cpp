class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>dp(n,1e9);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=grid[0][0];
                else{
                    int up =INT_MAX,left=INT_MAX;
                    if(i>0) up= dp[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=grid[i][j]+min(up,left);
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};