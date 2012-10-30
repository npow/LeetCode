class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        typedef map<int, vector<pair<int, int> > > map_t;
        map_t m;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                m[num[i]+num[j]].push_back(pair<int, int>(i, j));
            }
        }
        for (map_t::const_iterator it = m.begin(); it != m.end(); ++it) {
            map_t::const_iterator it2 = m.find(target - it->first);
            if (it2 == m.end()) continue;
            const vector<pair<int, int> > &v1 = it->second;
            const vector<pair<int, int> > &v2 = it2->second;
            for (int i = 0; i < v1.size(); ++i) {
                for (int j = 0; j < v2.size(); ++j) {
                    int a = v1[i].first;
                    int b = v1[i].second;
                    int c = v2[j].first;
                    int d = v2[j].second;
                    if (a == c || a == d || b == c || b == d) continue;
                    
                    vector<int> v;
                    v.push_back(num[a]);
                    v.push_back(num[b]);
                    v.push_back(num[c]);
                    v.push_back(num[d]);
                    if (!v.empty()) res.push_back(v);
                }
            }
            
        }
        for (int i = 0; i < res.size(); ++i) {
            sort(res[i].begin(), res[i].end());    
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
