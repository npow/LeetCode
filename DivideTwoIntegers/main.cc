class Solution {
public:
    #define abs_(x) ((unsigned)((x) ^ -1) + 1)
    int div_(unsigned dividend, unsigned divisor) {
        if (divisor == 1) return dividend;
        if (dividend < divisor) return 0;
        
        int quotient = 1;
        unsigned sum = divisor;
        while ((sum << 1) > sum && (sum << 1) < dividend) {
            quotient <<= 1;
            sum <<= 1;
        }

        return quotient + div_(dividend - sum, divisor);
    }
    int divide(int dividend, int divisor) {
        if (dividend < 0 && divisor < 0) return div_(abs_(dividend), abs_(divisor));
        else if (dividend < 0) return (-1 ^ div_(abs_(dividend), divisor)) + 1;
        else if (divisor < 0) return (-1 ^ div_(dividend, abs_(divisor))) + 1;
        return div_(dividend, divisor);
    }
};
