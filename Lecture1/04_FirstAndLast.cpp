class Solution {
private:
  int start(vector<int>& nums,int target){
      int low =0,high=nums.size()-1;
      int ans=-1;
      while(low<=high){
          int mid  = low+(high-low)/2;
          if(nums[mid]==target){
              ans=mid;
              high=mid-1;
          }
          else if(nums[mid]<target) low=mid+1;
          else high=mid-1;
      }
      return ans;
  }
  int last(vector<int>& nums,int target){
      int low =0,high=nums.size()-1;
      int ans=-1;
      while(low<=high){
          int mid  = low+(high-low)/2;
          if(nums[mid]==target){
              ans=mid;
              low=mid+1;
          }
          else if(nums[mid]<target) low=mid+1;
          else high=mid-1;
      }
      return ans;
  }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       /* int start=-1,last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                start=i;
                break;
            }
        }
        if(start==-1) return {-1,-1};
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                last=i;
                break;
            }
        }
        return {start,last};*/
        int low = start(nums,target);
        int high = last(nums,target);
        return {low,high};
    }
};