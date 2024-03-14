class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        long long low=1,high=x;
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long sq = mid*mid;
            if(sq==x) return mid;
            if(sq<x) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};