class Solution {
public:
    bool canJump(int A[], int n) {
        int farthestIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (farthestIndex >= i && i + A[i] > farthestIndex) {
                farthestIndex = i + A[i];
            }
        }
        return farthestIndex >= n - 1;
    }
};
