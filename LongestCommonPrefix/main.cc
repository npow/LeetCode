class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        if (strs.empty()) return prefix;
        int minLen = std::numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); ++i) {
            minLen = min((int)minLen, (int)strs[i].length());
        }
        for (int i = 0; i < minLen; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};
