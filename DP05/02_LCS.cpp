class Solution {
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        string s1=text1,s2=text2;
        vector<int>prev(s2.size()+1,0),curr(s2.size()+1,0);
        //now i have to think about the tabulation of this 
        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
          if(s1[ind1-1]==s2[ind2-1])  curr[ind2]= 1+prev[ind2-1];
          else curr[ind2]=0+max(prev[ind2],curr[ind2-1]);        
            }
            prev=curr;
        }
        return prev[text2.size()];
    }
};