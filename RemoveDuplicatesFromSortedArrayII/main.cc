class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        int j = 0;
        int nvisited = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[j]) {
                j++;
                A[j] = A[i];
                nvisited = 1;
            } else {
                nvisited++;
                if (nvisited == 2) {
                    j++;
                    A[j] = A[i];
                }
            }
        }
        return j + 1;
    }
};
