class Solution {
public:
    int reverse(int x) {
        if (x < 0) return -1*reverse(abs(x));
        int z = 0;
        while (x > 0) {
            z = 10*z + x%10;
            x = x/10;
        }
        return z;
    }
};
