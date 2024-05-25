class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
      int n = arr.size();
      if(n==k) return accumulate(arr.begin(),arr.end(),0);
     int i=0,j=n-k,sum=0,ans=0;
     for(int last=j;last<n;last++) sum+=arr[last];
     ans=sum;
     for(;j<n;j++){
         sum+=(arr[i]-arr[j]);
         i++;
         ans=max(ans,sum);
     }
      return ans;
    }
};