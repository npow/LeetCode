class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        for (int i = grid.size()-1; i >= 0; --i) {
            for (int j = grid[i].size()-1; j >= 0; --j) {
                if (i + 1 < grid.size()) {
                    if (j + 1 < grid[i].size()) {
                        grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
                    } else {
                        grid[i][j] += grid[i+1][j];
                    }
                } else {
                    if (j + 1 < grid[i].size()) {
                        grid[i][j] += grid[i][j+1];
                    }
                }
            }
        }
        return grid[0][0];
    }
};
