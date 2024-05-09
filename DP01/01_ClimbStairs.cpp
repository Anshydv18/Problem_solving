class Solution {
    private:
    int solve(int n,vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int step1 = solve(n-1,dp);
        int step2 = solve(n-2,dp);
        return dp[n] = step1 + step2;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+2,-1);
        return solve(n+1,dp);
    }
};