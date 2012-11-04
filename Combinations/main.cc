class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        combine_(n, k, 1, vector<int>(), res);
        return res;
    }
    void combine_(int n, int k, int i, vector<int> v, vector<vector<int> >& res) {
        if (v.size() == k) {
            res.push_back(v);
        } else if (i <= n) {
            combine_(n, k, i+1, v, res);
            v.push_back(i);
            combine_(n, k, i+1, v, res);
        }
    }
};
