class Solution {
    int possible(vector<int>& ds,int k,int days){
        int cnt=0;
        int ans=0;
        for(int i=0;i<ds.size();i++){
            if(cnt==k){ans++; cnt=0;}
            if(ds[i]<=days) cnt++;
            else cnt=0;
        }
        if(cnt==k) ans++;
        return ans;
    }
public:
    int minDays(vector<int>& ds, int m, int k) {
        int low= *min_element(ds.begin(),ds.end());
        int high=*max_element(ds.begin(),ds.end());
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int poss = possible(ds,k,mid);
            if(poss>=m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};