class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if((mid&1 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1])) low=mid+1;
            else high=mid-1;
        }
        return nums[low];
    }
};