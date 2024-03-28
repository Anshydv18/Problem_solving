int Solution::findMedian(vector<vector<int> > &A) {
    vector<int>ds;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            ds.push_back(A[i][j]);
        }
    }
    sort(ds.begin(),ds.end());
    return ds[ds.size()/2];
}
