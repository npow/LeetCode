class Solution {
public:
    double pow(double x, int n) {
        if (fabs(x - 1.0) < .0000001) {
            return 1;
        } else if (fabs(fabs(x) - 1.0) < .0000001) {
            return n % 2 == 0 ? 1 : -1;
        } else if (n < 0) {
            return 1.0/pow(x, -1*n); 
        } else if (n == 0) {
            return 1;
        } else if (n % 2 == 0) {
            return pow(x*x, n/2);
        } else {
            if (n == 1) {
                return x;
            } else {
                return x*pow(x, n-1);
            }
        }
    }
};
