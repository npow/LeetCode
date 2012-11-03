class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
            while (A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            } 
            ++i;
        }
        for (i = 0; i < n; ++i) {
            if (A[i] != i+1) break;
        }
        return i+1;
    }
};
