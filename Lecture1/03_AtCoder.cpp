#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  vector<int>ds;
  for(int i=0;i<n;i++) {
    int x; cin>>x;
    ds.push_back(x);
  }
  sort(ds.begin(),ds.end());
  while(q--){
    int d; cin>>d;
    auto it = lower_bound(ds.begin(),ds.end(),d)-ds.begin();
    cout<<n-it<<endl;
  }
}
