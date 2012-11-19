class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        if (!M) return false;
        int N = matrix[0].size();
        
        int low = 0, high = M-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (target < matrix[mid][0]) {
                high = mid - 1;
            } else if (target > matrix[mid][0]) {
                low = mid + 1;
            } else {
                return true;
            }
        }
        high = min(low, M-1);
        low = max(low-1, 0);
        return binary_search(matrix[high].begin(), matrix[high].end(), target) ||
               binary_search(matrix[low].begin(), matrix[low].end(), target);
    }
};
