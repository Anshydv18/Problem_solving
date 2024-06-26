class Solution {
    
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=1;
                else{
                    int left =0,up=0;
                    if(i>=1) up=dp[j];
                    if(j>=1) left=temp[j-1];
                    temp[j]=left+up;
                }

            }
            dp=temp;
        }
        return dp[n-1];
    }
};