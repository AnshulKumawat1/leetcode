class Solution {
public:
     bool solve(int r,int c,int ro,int co){
   if(r==ro && c==co) return false;
   return true;
     }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
            int ans=-1;
            queue<pair<pair<int,int>,int>>q;
            q.push({{e[0],e[1]},0});
            vector<vector<int>>vis(maze.size(),vector<int>(maze[0].size(),0));
            vis[e[0]][e[1]]=1;
            int dc[4]={0,0,-1,1};
            int dr[4]={-1,1,0,0};
            while(q.size()>0){
                int r=  q.front().first.first;
                int c=  q.front().first.second;
                int s=  q.front().second;
                  q.pop();
                  if((r== 0 || c==0 || r==maze.size()-1 || c==maze[0].size()-1 ) && solve(r,c,e[0],e[1])) return s;
                  for(int i=0;i<4;i++){
                      int nrow=r+dr[i]; int ncol=c+dc[i];
                      if(nrow>=0 && ncol>=0 && nrow<maze.size() && ncol <maze[0].size() && vis[nrow][ncol]==0 && maze[nrow][ncol]!='+'){
                          vis[nrow][ncol]=1;
                          q.push({{nrow,ncol},s+1});
                      }
                  }
            }
            return -1;
    }
};