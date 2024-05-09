class Solution {
    int dp[1001];
    int f(int ind,int st,vector<int>& nums){
        if(ind<0 || ind<st) return 0;
        if(ind==st) return nums[st];
        
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind-2,st,nums);

        int nonpick = f(ind-1,st,nums);
        return dp[ind]=max(pick,nonpick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int ans2 = INT_MIN;
        int ans1 = f(nums.size()-1,1,nums);
         memset(dp,-1,sizeof(dp));
       if(nums.size()>1)  ans2 = f(nums.size()-2,0,nums);
        return max(ans1,ans2);
    }
};