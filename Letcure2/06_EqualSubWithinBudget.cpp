class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>ds;
        ds.push_back(0);
        for(int i=0;i<s.length();i++){
            ds.push_back(abs(s[i]-t[i]));
        }
        
        for(int i=1;i<ds.size();i++) ds[i]+=ds[i-1];
        for(auto x:ds) cout<<x<<" ";
        int ans=0;
        for(int i=0;i<ds.size();i++){
            int get = ds[i]-maxCost;
            bool res = binary_search(ds.begin(),ds.begin()+i,get);
            auto it = lower_bound(ds.begin(),ds.begin()+i,get)-ds.begin();
            auto it2 = upper_bound(ds.begin(),ds.begin()+i,get)-ds.begin();
            if(res){
                if(ans<i-it) ans=i-it;
            }
            else if(ans<i-it2) ans=i-it2;
        }
        return ans;
    }
};