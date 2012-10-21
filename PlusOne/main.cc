class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += carry;
            if (digits[i] > 9) {
                carry = digits[i] / 10;
                digits[i] %= 10;
            } else {
                carry = 0;
            }
        }
        vector<int> res;
        if (carry) {
            res.push_back(carry);
        }
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};
