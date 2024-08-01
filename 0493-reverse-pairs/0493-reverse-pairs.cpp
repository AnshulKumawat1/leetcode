#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long , null_type, less_equal<long long >, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        unordered_map<long ,long >m; pbds s; long long  ans=0;
        for(auto it:nums){
           long long  no=2*1ll*it;
          long long  a=s.order_of_key(no)+m[no];
            ans+=s.size()-a;
            s.insert(it); m[it]++;
        }
        return ans;

    }
};