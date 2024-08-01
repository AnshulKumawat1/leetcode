class Solution {
public:
     void create( vector<vector<int>>&grid, vector<vector<int>>&cel,int & mid){
         int m=grid.size(); int n=grid[0].size();
        for(int i=0;i<mid;i++){
            int x=cel[i][0]-1; int y=cel[i][1]-1;
            grid[x][y]=1;
        }
        

     }
     bool solve( vector<vector<int>>&grid){
        int m=grid.size(); int n=grid[0].size();
    
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<tuple<int,int>>q;
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]!=1){
                vis[0][i]=1; q.emplace(0,i);
            }
        }

        int dx[4]={0,0,1,-1}; int dy[4]={-1,1,0,0};

        while(q.size()>0){
           auto [r,c]=q.front();q.pop(); 
           if(r==m-1) return true;
           for(int i=0;i<4;i++){
            int nr=r+dx[i]; int nc=c+dy[i];
           
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]!=1 && grid[nr][nc]!=1){
                q.emplace(nr,nc); vis[nr][nc]=1;
            }
           }

        }
        return false;
     }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
     int l=1; int h=row*col;
     int ans=0;
     while(h>=l){
        int mid=(l+h)>>1;
        vector<vector<int>>grid(row,vector<int>(col,0));
        create(grid,cells,mid);
       if(solve(grid)==true){
        ans=mid; l=mid+1;
       }
         else h=mid-1;

     }
     return ans;


    }
};