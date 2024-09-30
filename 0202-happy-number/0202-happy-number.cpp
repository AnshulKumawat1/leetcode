class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        return true;
        int s = 0;
        while (n > 1) {
            while (n > 0) {
                int m = n % 10;
                s += m * m;
                n /= 10;
            }
            if (s == 1) {
                return true;
            }
            n = s;
            s = 0;
            if (n == 4) {  
                return false;
            }
        }
        return false;
    }
};