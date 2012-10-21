class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, pair<string, vector<string> > > m;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i]; // copy
            sort(s.begin(), s.end());
            if (m.find(s) == m.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                m[s] = pair<string, vector<string> >(strs[i], v);
            } else {
                m[s].second.push_back(strs[i]);
            }
        }
        vector<string> res;
        for (map<string, pair<string, vector<string> > >::const_iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second.second.size() > 1) {
                res.insert(res.end(), it->second.second.begin(), it->second.second.end());
            }
        }
        return res;
    }
};
