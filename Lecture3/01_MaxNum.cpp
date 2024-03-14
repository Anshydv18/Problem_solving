#include<bits/stdc++.h>
using namespace std;

bool possible(int arr[],int n,int s,int window){
    int sum=0;
    int i=0,j=0;
    while(i<window) sum+=arr[i++];
    
    if(sum>s) return false;
    for(;i<n;i++){
        sum+=arr[i];
        sum-=arr[j++];
        if(sum>s) return false;
    }
    return true;
}

int main(){
    int n; cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++) cin>>arr[i];
    //solution
    
    int s; cin>>s;
    int low=0,high=n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(possible(arr,n,s,mid)) low=mid+1;
        else high=mid-1;
    }
    cout<<high<<endl;
}