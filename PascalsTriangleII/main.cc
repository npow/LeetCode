class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if (rowIndex == 0) {
            v = vector<int>(1, 1);
        } else if (rowIndex == 1) {
            v = vector<int>(2, 1);
        } else {
            v = vector<int>(2, 1);
            for (int j = 2; j <= rowIndex; ++j) {
                int prev = v[0];
                for (int i = 1; i < v.size(); ++i) {
                    int curr = v[i];
                    v[i] += prev;
                    prev = curr;
                }
                v.push_back(1);
            }
        }
        return v; 
    }
};

