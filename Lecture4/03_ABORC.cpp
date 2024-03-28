/*  https://leetcode.com/problems/nth-magical-number/ */
/* this is similar problem to the article shared */
class Solution {
private:
  bool possible(int n,int a,int b,long long mid){
     long long mid_a = mid/a;
     long long mid_b = mid/b;
     long long lcm = (a*b)/(__gcd(a,b));
     long long mid_ab = mid/lcm;
     long long numbers = mid_a + mid_b - mid_ab;
     return numbers>=n;
  }
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9+7;
        long long low=2,high=1e15;
        while(low<high){
            long long mid = low+(high-low)/2;
            if(possible(n,a,b,mid)) high=mid;
            else low=mid+1;
        }
        return low%mod;
    }
};