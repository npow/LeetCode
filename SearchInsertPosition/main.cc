class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;          
            if (target < A[mid]) {
                high = mid - 1;
            } else if (target > A[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low;
    }
};
