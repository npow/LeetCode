class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int N = S.size();
        int MAX = 1 << N;
        vector<vector<int> > res;
        for (int i = 0; i < MAX; ++i) {
            vector<int> v;
            int j = i;
            int d = 0;
            while (j > 0) {
                if (j & 1) {
                    v.push_back(S[d]);
                }
                j >>= 1;
                d++;
            }
            res.push_back(v);
        }
        return res;
    }
};
