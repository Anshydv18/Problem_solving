class Solution {
    long long  dp[100000];
    long long f(int ind,vector<vector<int>>& questions){

        if(ind>=questions.size()) return 0;
        //if(ind==questions.size()-1) return questions[ind][0];
        if(dp[ind]!=-1) return dp[ind];
        long long pick = questions[ind][0]+f(ind+questions[ind][1]+1,questions);
        long long nonpick =0+f(ind+1,questions);

        return dp[ind]=max(pick,nonpick);

    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return f(0,questions);
    }
};