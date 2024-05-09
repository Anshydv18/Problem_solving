class Solution {
    private:
    int f(int ind,int tar,vector<long long>& res,vector<vector<int>>& dp){
        if(tar==0) return 0;
        if(ind==0){
            if(tar%res[0]==0) return tar/res[0];
            else return 1e9;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int pick=INT_MAX;
        if(tar>=res[ind]) pick = 1+f(ind,tar-res[ind],res,dp);
        int nonpick = 0+f(ind-1,tar,res,dp);
        return dp[ind][tar]= min(pick,nonpick);
    }
public:
    int numSquares(int n) {
        int k =sqrt(n);
        vector<long long>res;
        for(int i=0;i<k;i++) res.push_back((i+1)*(i+1));
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return f(k-1,n,res,dp);
    }
};