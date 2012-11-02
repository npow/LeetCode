class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) {
            return res;
        }
        if (numRows >= 1) {
            res.push_back(vector<int>(1, 1));
        }
        if (numRows >= 2) {
            res.push_back(vector<int>(2, 1));
        }
        for (int i = 2; i < numRows; ++i) {
            vector<int> v(1, 1);
            for (int j = 1; j < i; ++j) {
                v.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};
