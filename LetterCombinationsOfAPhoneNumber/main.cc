class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static map<char, string> m;
        if (m.empty()) {
            m['1'] = "";
            m['2'] = "abc";
            m['3'] = "def";
            m['4'] = "ghi";
            m['5'] = "jkl";
            m['6'] = "mno";
            m['7'] = "pqrs";
            m['8'] = "tuv";
            m['9'] = "wxyz";
            m['0'] = " ";
        }
        
        vector<string> res;
        if (digits.empty()) return vector<string>(1, "");
        char c = digits[0];
        string rest = digits.substr(1);
        for (int i = 0; i < m[c].size(); ++i) {
            vector<string> v = letterCombinations(rest);
            for (int j = 0; j < v.size(); ++j) {
                res.push_back(m[c][i] + v[j]);
            }
        }
        return res;
    }
};
