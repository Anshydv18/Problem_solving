class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>hash(nums.size(),INT_MAX);
        hash[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<=i+nums[i] && j<nums.size();j++){
                hash[j]=min(hash[j],hash[i]+1);
            }
        }
        return hash[nums.size()-1];
    }
};