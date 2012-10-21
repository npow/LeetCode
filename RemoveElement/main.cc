class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int numRemoved = 0;
        for (int i = n-1; i >=0; --i) {
            if (A[i] == elem) {
                memmove(A+i, A+i+1, (n-i-1)*sizeof(int));
                ++numRemoved;
            }
        }
        return n-numRemoved;
    }
};
