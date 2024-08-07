class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int keys=0; int m=grid.size(); int n=grid[0].size();
        int state=0; queue<tuple<int,int,int,int>>q;
        set<tuple<int,int,int>>s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@') { q.emplace(i,j,state,0); s.emplace(i,j,state);}
                if(grid[i][j]>='a' && grid[i][j]<='z') keys++;
            }
        }
 
         int final=(1<<keys)-1;
         while(q.size()>0){
           auto [r,c,state,steps]=q.front();q.pop();
           if(state==final) return steps;
           int x[4]={-1,1,0,0};
           int y[4]={0,0,-1,1};
           for(int i=0;i<4;i++){
            int nr=r+x[i]; int nc=c+y[i];
           if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!='#'){
            // tala
             if(grid[nr][nc]>='A' && grid[nr][nc]<='Z'){
                int  ch=grid[nr][nc]-'A';
                  int mask=(1<<ch);
                  if((state & mask)!=0){
                  if(s.find({nr,nc,state})==s.end()){
                    s.emplace(nr,nc,state); q.emplace(nr,nc,state,steps+1);
                  }
                  }
             }
             else if(grid[nr][nc]>='a' && grid[nr][nc]<='z'){
                    int ch=grid[nr][nc]-'a';
                    int mask=(1<<ch);
                    int nm=state|mask;
                    if(s.find({nr,nc,nm})==s.end()){
                        s.emplace(nr,nc,nm); q.emplace(nr,nc,nm,steps+1);
                    }
             }
             else  {
                  if(s.find({nr,nc,state})==s.end()){
                    s.emplace(nr,nc,state); q.emplace(nr,nc,state,steps+1);
                  } 
             }
           } 
           }






         }

        return -1;


    }
};