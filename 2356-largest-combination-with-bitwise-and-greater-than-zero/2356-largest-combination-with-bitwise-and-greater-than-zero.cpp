class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int>count(31,0);
        for(int i=0;i<=30;i++){
           for(auto it:c){
            int bit=(it)&(1<<i);
             if(bit!=0) count[i]++;
           }
        }
        return *max_element(count.begin(),count.end());
    }
};