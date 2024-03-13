//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   public:
	int NthRoot(int n, int m)
	{
	    
	    if(n==1) return m;
	    long long low=1,high=m;
	    while(low<=high){
	        long long mid = low+(high-low)/2;
	       long long res=1;
	       for(int i=0;i<n;i++){ res*=mid; 
	       if(res>m){res=m+1; break;}}
	        if(res==m) return mid;
	        if(res<m) low=mid+1;
	        else high=mid-1;
	        
	    }
	    if(pow(high,n)!=m) return -1;
	    return high;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends