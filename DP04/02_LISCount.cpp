class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size(), maxm = 1;
   vector<int>dp(n,1),cnt(n,1);
   for(int i=0;i<n;i++){
       for(int prev=0;prev<i;prev++){
           if(arr[prev]<arr[i] && dp[i]<1+dp[prev]){
               dp[i]=1+dp[prev];
               cnt[i]=cnt[prev];
           }
           else if(arr[prev]<arr[i] && dp[i]==1+dp[prev])cnt[i]+=cnt[prev];
          
       }
       maxm=max(maxm,dp[i]);
   }
   int ans=0;
   for(int i=0;i<n;i++){
       if(dp[i]==maxm) ans+=cnt[i];
   }
   return ans;
    }
};