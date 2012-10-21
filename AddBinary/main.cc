class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            return addBinary(b, a);
        } else if (b == "0") {
            return a;
        }
        string s;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (int i = 0; i < b.length(); ++i) {
            int d = b[i] - '0' + a[i] - '0' + carry;
            if (d > 1) {
                carry = 1;
                d %= 2;
            } else {
                carry = 0;
            }
            s += (d ? "1" : "0");
        }
        reverse(s.begin(), s.end());
        string prefix = a.substr(b.length(), a.length() - b.length());
        if (prefix != "" || carry) {
            reverse(prefix.begin(), prefix.end());
            s = addBinary(prefix, carry ? "1" : "0") + s;
        }
        return s;
    }
};


