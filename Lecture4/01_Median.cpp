class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums, vector<int>& nums2) {
        vector<int>ds;
        int i=0,j=0;
        while(i<nums.size() && j<nums2.size()){
            if(nums[i]<nums2[j]) ds.push_back(nums[i++]);
            else ds.push_back(nums2[j++]);
        }
        while(i<nums.size()) ds.push_back(nums[i++]);
        while(j<nums2.size()) ds.push_back(nums2[j++]);

        int a=-1,b=-1;
        if(ds.size()%2){
            a=ds.size()/2;
            b=a;
        }
        else{
            a=ds.size()/2;
            b=a-1;
        }
        return ((double)(ds[a]+ds[b]))/2.0000;
    }
};