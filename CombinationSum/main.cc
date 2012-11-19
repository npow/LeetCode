class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        combinationSum(candidates, target, 0, 0, vector<int>(), res);
        for (int i = 0; i < res.size(); ++i) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        return res;
    }
    void combinationSum(vector<int> &candidates, int target, int i, int currSum, vector<int> currComb, vector<vector<int> > &res) {
        if (i >= candidates.size() || currSum > target) return;
        if (currSum == target) {
            res.push_back(currComb);
            return;
        } else {
            vector<int> A = currComb;
            A.push_back(candidates[i]);
            combinationSum(candidates, target, i, currSum + candidates[i], A, res);
            combinationSum(candidates, target, i+1, currSum, currComb, res);
        }
    }
};
