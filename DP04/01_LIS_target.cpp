class Solution {
    
    int solve(int ind,vector<int>&nums,int target,vector<vector<int>>& dp){
        if(target<0) return -1e9;
        if(ind==nums.size()){
            if(target==0) return 0;
            else return -1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick = 1 + solve(ind+1,nums,target-nums[ind],dp);
        int skip  =  solve(ind+1,nums,target,dp);
        return dp[ind][target]= max(pick,skip);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        int ans= solve(0,nums,target,dp);
        if(ans<0) return -1;
        return ans;
    }
};