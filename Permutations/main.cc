class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        return permute(num, vector<int>());
    }
    vector<vector<int> > permute(const vector<int>& digits, const vector<int>& curr) {
      vector<vector<int> > res;
      if (digits.empty()) {
        res.push_back(curr);
        return res;
      }
      for (int i = 0; i < digits.size(); ++i) {
        vector<int> tmpCurr = curr; // copy
        vector<int> tmpDigits = digits;
        tmpDigits.erase(remove(tmpDigits.begin(), tmpDigits.end(), digits[i]), tmpDigits.end());
        tmpCurr.push_back(digits[i]);
        vector<vector<int> > v = permute(tmpDigits, tmpCurr);
        res.insert(res.end(), v.begin(), v.end());
      }
      return res;
    }
};
