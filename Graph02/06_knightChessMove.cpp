
const int INF = 1e9;
 
int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
 
bool isValid(int x, int y, int n, int m){
    return x >= 0 && y >= 0 && x < n && y < m;
}

 
int Solution::knight(int a, int b, int c, int d, int e, int f) {
    vector<vector<int>> dis(a, vector<int>(b, INF));
   
    queue<pair<int,int>> q;
    pair<int,int> src = {--c, --d};
   
    q.push(src);
    dis[c][d] = 0;
   
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i){
            int X = x + dx[i], Y = y + dy[i];
            if(isValid(X, Y, a, b) && dis[X][Y] == INF){
                q.push({X, Y});
                dis[X][Y] = dis[x][y] + 1;
            }
        }
    }
   
    --e; --f;
   
    if(dis[e][f] == INF) return -1;
    return dis[e][f];
   
   
}