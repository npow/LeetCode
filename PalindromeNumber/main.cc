class Solution {
public:
    typedef long long long_t;
    long_t reverse(long_t x) {
        if (x < 0) return -1*reverse(abs(x));
        long_t z = 0;
        while (x > 0) {
            z = 10*z + x%10;
            x /= 10;
        }
        return z;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long_t xx = static_cast<long_t>(x);
        return xx == reverse(xx);
    }
};
