class Solution {
public:
    int findMin(vector<int>& arr) {
        int minm =INT_MAX;
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[low]<=arr[mid]){
                minm = min(minm,arr[low]);
                low=mid+1;
            }
            else{
                minm=min(minm,arr[mid]);
                high=mid-1;
            }
        }
        return minm;
    }
};