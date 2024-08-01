class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            int x = t.second.first;
            int y = t.second.second;
            if(x == m-1 && y == n-1){
                return t.first;
            }
            int original = grid[x][y];
            for(int i = 1;i<=4;++i){                
                if(x + dx[i-1] < m && y+dy[i-1] < n && x+dx[i-1] >= 0 && y+dy[i-1] >=0  ){
                    if(!(original == i) + t.first < dist[x + dx[i-1]][y+dy[i-1]]){
                    
                        dist[x + dx[i-1]][y+dy[i-1]] = !(original == i) + t.first;
                        pq.push({!(original == i) + t.first,{x + dx[i-1],y+dy[i-1]}});
                    }
                    
                }                
            }
        }
        return 0;
    }
};