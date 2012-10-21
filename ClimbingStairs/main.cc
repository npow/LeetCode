class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n);
        return climbStairs_(n, v);
    }
    int climbStairs_(int n, vector<int>& v) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            if (!v[n-2]) {
                v[n-2] = climbStairs_(n-2, v);
            }
            if (!v[n-1]) {
                v[n-1] = climbStairs_(n-1, v);
            }
            return v[n-1] + v[n-2];
        }
    }
};
