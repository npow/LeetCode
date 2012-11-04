class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        combinationSum2(num, target, 0, vector<int>(), res);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    void combinationSum2(vector<int> &num, int target, int i, vector<int> v, vector<vector<int> > &res) {
        if (target == 0) {
            if (!v.empty()) {
                sort(v.begin(), v.end());
                res.push_back(v);
            }
        } else if (target > 0 && i < num.size()) {
            combinationSum2(num, target, i+1, v, res);
            v.push_back(num[i]);
            combinationSum2(num, target-num[i], i+1, v, res);
        }
    }
};
