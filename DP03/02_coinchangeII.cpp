class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        prev[0]=1;
        for(int i=0;i<=amount;i++) {
            if(i%coins[0]==0) prev[i]=1;
        }
        for(int ind =1;ind<n;ind++){
            curr[0]=1;
        for(int sum=1;sum<=amount;sum++){
            int pick=0;
            if(coins[ind]<=sum) pick = curr[sum-coins[ind]];
            int nonpick = prev[sum];
            curr[sum]= pick+nonpick;
        }
        prev=curr;
        }
        return prev[amount];
    }
};