class Solution {
    int f(int ind,int amount , vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick =INT_MAX;
        if(coins[ind]<=amount) pick=1+f(ind,amount-coins[ind],coins,dp);
        int nonpick = 0+f(ind-1,amount,coins,dp);
        return dp[ind][amount]=min(pick,nonpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= f(coins.size()-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};