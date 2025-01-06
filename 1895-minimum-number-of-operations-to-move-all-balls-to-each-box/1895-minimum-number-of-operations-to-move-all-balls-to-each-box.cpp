class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();

        vector<int> ans;
        int sum = 0;
        int ones = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') {
                ones++;
                sum += i;
            }
        }

        int tempSum = sum;
        int leftOnes = 0;
        for(int i=0;i<n;i++) {
            ans.push_back(tempSum);

            if(s[i] == '1') {
                leftOnes++;
                ones--;
            }

            tempSum -= ones;
            tempSum += leftOnes;
        }

        return ans;
    }
};