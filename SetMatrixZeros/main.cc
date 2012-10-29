class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = -1, col = -1;
        int M = matrix.size();
        if (!M) return;
        int N = matrix[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!matrix[i][j]) {
                    row = i;
                    col = j;
                    goto endLoop;
                }
            }
        }
        endLoop:
        if (row == -1 && col == -1) return;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!matrix[i][j]) {
                    matrix[row][j] = 0;
                    matrix[i][col] = 0;
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            if (!matrix[i][col] && i != row) {
                for (int j = 0; j < N; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < N; ++j) {
            if (!matrix[row][j] && j != col) {
                for (int i = 0; i < M; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < M; ++i) matrix[i][col] = 0;
        for (int j = 0; j < N; ++j) matrix[row][j] = 0;
    }
};
