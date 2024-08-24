class KthLargest {
public:
     multiset<int>s; int size;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums) {s.insert(it);
        if(s.size()>k) s.erase(s.begin());}
        size=k;
    }
    
    int add(int val) {
        s.insert(val);
        if(s.size()>size)   s.erase(s.begin());
      
        return *s.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */