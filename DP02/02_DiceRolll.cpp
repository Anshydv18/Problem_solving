class Solution {
    int dp[31][1001];
    int solve(int n,int k,int target){
        if(target<=0) return 0;
        if(n==1){
            if(target<=k) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=solve(n-1,k,target-i);
            ans=ans%1000000007;
        } 
        return dp[n][target]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};