class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty() || s.size() == 1) return s.size();
        map<int, int> m;
        m[s.size()-1] = 1;
        for (int i = s.size()-2; i >= 0; --i) {
            int ii = i + 1;
            bool found = false;
            for (; ii < s.size() && ii <= i + m[i+1]; ++ii) {
                if (s[ii] == s[i]) {
                    found = true;
                    break;
                }
            }
            m[i] = found ? ii - i : m[i+1] + 1;
        }
        int longestLen = 0;
        for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second > longestLen) longestLen = it->second;
        }
        return longestLen;
    }
};
