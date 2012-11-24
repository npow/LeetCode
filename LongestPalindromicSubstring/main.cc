class Solution {
public:
    string longestPalindrome(string s) {
        string retval = "";
        for (int i = 0; i < s.size(); ++i) {
            int j;
            for (j = 1; j<=i && j+i < s.size() && i-j >= 0; ++j) {
                if (s[i-j] != s[i+j]) {
                    break;
                }
            }
            --j;
            string p1 = s.substr(i-j, 2*j+1);
            for (j = 0; j<i && j+i < s.size() && i-j-1 >= 0; ++j) {
                if (s[i-j-1] != s[i+j]) {
                    break;
                }
            }
            string p2 = s.substr(i-j, 2*j);
            if (p1.size() > retval.size()) retval = p1;
            if (p2.size() > retval.size()) retval = p2;
        }
        return retval;
    }
};
