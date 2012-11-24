class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num)) {
            res.push_back(num);
        }
        return res;
    }
    bool next_permutation(vector<int> &v) {
        if (v.empty() || v.size() == 1) return false;
        vector<int>::iterator i = v.end() - 1;
        // 1. find i and ii such that ii == i+1 and v[i] < v[ii]
        // 2. find right-most j such that j > i and v[j] > v[i] (j >= ii)
        // 3. swap v[i], v[j]
        // 4. v.reverse(ii, end)
        for (;;) {
            vector<int>::iterator ii = i--;
            if (*i < *ii) {
                vector<int>::iterator j = v.end() - 1;
                while (*j <= *i) --j;
                iter_swap(i, j);
                reverse(ii, v.end());
                return true;
                
            }
            if (i == v.begin()) {
                reverse(v.begin(), v.end());
                return false;
            }
        }
    }
};
