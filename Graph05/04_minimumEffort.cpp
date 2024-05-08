class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==m-1) return dist;
            for(int i=0;i<4;i++){
                int r = row + drow[i];
                int c = col + dcol[i];
                if((r>=0 && r<n) && (c>=0  && c<m)){
                    int newDist = abs(grid[r][c]-grid[row][col]);
                    int dd = max(newDist,dist);
                    if(dd<dis[r][c]){
                        dis[r][c]=newDist;
                        pq.push({dd,{r,c}});
                    }
                }
            }
        }
        return 0;
    }
};