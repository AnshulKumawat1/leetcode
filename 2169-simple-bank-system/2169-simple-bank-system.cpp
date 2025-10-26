class Bank {
public:    int n; vector<long long >v;
    Bank(vector<long long>& balance) {
        n=balance.size();
        v.resize(n+1,0);
        for(int i=1;i<=n;i++){
               v[i]=balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>=1 && account1<=n && account2>=1 && account2<=n  ){
            if(v[account1]-money>=0){
                v[account1]-=money; v[account2]+=money; return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>=1 && account<=n){
            v[account]+=money; return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
         if(account>=1 && account<=n){
          if(v[account]-money>=0){
            v[account]-=money; return true;
          }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */