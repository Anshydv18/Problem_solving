// memoization
class Solution {
    int dp[2501][2501];
    int solve(int ind,int prev_ind,vector<int>& nums){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int skip = 0+solve(ind+1,prev_ind,nums);
        int pick =0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]) pick = 1+solve(ind+1,ind,nums);
        return dp[ind][prev_ind+1]= max(pick,skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};

//2nd approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]) dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        int ans =*max_element(dp.begin(),dp.end());
        return ans;
    }
};

//3rd approach
class Solution {
private:
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int index=nums.size()-1;index>=0;index--){
            for(int prev_index=index-1;prev_index>=-1;prev_index--){
                    int nottake = 0+dp[index+1][prev_index+1];
                    int take=0;
                    if(prev_index==-1 || nums[index]>nums[prev_index]) take = 1+dp[index+1][index+1];
                     dp[index][prev_index+1]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};

///binary search Approach

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        ds.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>ds.back()) ds.push_back(nums[i]);
            else{
                int low = lower_bound(ds.begin(),ds.end(),nums[i])-ds.begin();
                ds[low]=nums[i];
            }
        }
        return ds.size();
    }
};