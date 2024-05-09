class Solution {
    int dp[1001];
    private:
    int solve(int ind,vector<int>& nums){
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+solve(ind-2,nums);
        int nonpick =solve(ind-1,nums);
       return dp[ind]= max(pick,nonpick);
    }
public:
    int rob(vector<int>& nums) {
        fill(dp,dp+1000,-1);
        return solve(nums.size()-1,nums);
    }
};