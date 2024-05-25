class Solution {
    bool f(int i,int j, string &s,string &p,vector<vector<int>>& dp){
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>0){
            for(int ii=1;ii<=j;ii++){
                if(p[ii-1]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j-1]=='*') return dp[i][j]=f(i-1,j,s,p,dp)|f(i,j-1,s,p,dp);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};