  #include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
class MedianFinder {
public:
 
    pbds a;
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        a.insert(num);
    }
    
    double findMedian() {
        if(a.size()%2==1){
            int mid=a.size()/2;
            return *a.find_by_order(mid);
        }
        else{
             int mid=a.size()/2; 
            double ak=*a.find_by_order(mid);
            double b=*a.find_by_order(mid-1);
            return ((ak+b)*1.00)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */