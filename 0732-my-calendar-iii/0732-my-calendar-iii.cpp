class MyCalendarThree {
public:
   map<int,int>m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int ans=0;  int t=0;
        for(auto it:m){
          t+=it.second;
          ans=max(ans,t);
        }
      
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */