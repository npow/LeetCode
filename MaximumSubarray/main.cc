class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;
        map<int, int> m;
        m[n-1] = A[n-1];
        for (int i = n-2; i >= 0; --i) {
            m[i] = max(A[i]+m[i+1], A[i]);
        }
        int maxSum = numeric_limits<int>::min();
        for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
            maxSum = max(maxSum, it->second);
        }
        return maxSum;
    }
};
