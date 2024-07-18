#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

class Solution {
public:
    void myerase(pbds &t, int v){
      int rank = t.order_of_key(v);//Number of elements that are less than v in t
      pbds::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
        t.erase(it);
}
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
           pbds a;
           int i=0,j=0;
           vector<double>ans;
           while(j<nums.size()){
            a.insert(nums[j]);
            if(j-i+1==k){
                if(k%2==1) {
                    int ind=k/2;
                   double e= *a.find_by_order(ind); 
                   ans.push_back(e*1.00000);
                }
                else{
                    int ind=k/2;
                    double e=*a.find_by_order(ind);
                    double prev=*a.find_by_order(ind-1);
                    double final=((e+prev)*1.00000)/2;
                    ans.push_back(final);
                }
               int num=nums[i];
               myerase(a,num); i++;
            }
            j++;
           }
           return ans;
    }
};