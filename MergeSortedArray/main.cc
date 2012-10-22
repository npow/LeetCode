class Solution {
public:
    void merge_(int A[], int m, int B[], int n, int i, int j) {
        if (m == 0) {
            memcpy(A, B, n*sizeof(B));
            return;
        } else if (n == 0) {
            return;
        } else if (B[n-1] < A[0]) {
            memcpy(A+n, A, m*sizeof(A));
            memcpy(A, B, n*sizeof(B)); 
            return;
        } else if (i == m) {
            memcpy(A+m, B+j, (n-j)*sizeof(B));
            return;
        }
        if (A[i] > B[j]) {
            swap(B[j], A[i]);
            int k = j;
            while (k < n-1 && B[k] > B[k+1]) {
                swap(B[k], B[k+1]);
                ++k;
            }
        }
        i++;
        merge_(A, m, B, n, i, j);
    }
    void merge(int A[], int m, int B[], int n) {
        merge_(A, m, B, n, 0, 0);
    }
};
