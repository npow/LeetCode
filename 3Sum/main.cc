class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() < 3) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i <= num.size() - 3; ++i) {
            int a = num[i];
            int k = i + 1;
            int l = num.size() - 1;
            while (k < l) {
                int b = num[k];
                int c = num[l];
                if (a + b + c == 0) {
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    res.push_back(v);
                    --l;
                    ++k;
                } else if (a + b + c > 0) {
                    --l;
                } else {
                    ++k;
                }
            }
        }
    
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
