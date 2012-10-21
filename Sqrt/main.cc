class Solution {
public:
    int sqrt(int x) {
        if (x == 1 || x == 0) return x;
        double x1 = x/2.0;
        while (x1*x1 -x > .0001) {
            x1 = (x1 + x/x1) / 2.0;
        }
        return x1;
    }
};
