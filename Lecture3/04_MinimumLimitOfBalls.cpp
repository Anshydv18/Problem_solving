class Solution {
    private:
    bool operation(vector<int>& ds,int mid,int k){
        int cnt=0;
        for(auto x:ds){
            cnt+=(x-1)/mid;
        }
        if(cnt>k) return true;
        return false;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=1e9;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(operation(nums,mid,maxOperations)) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};