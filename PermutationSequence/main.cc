class Solution {
public:
    int factorial(int x) {
      int res = 1;
      for (int i = 2; i <= x; ++i) res *= i;
      return res;
    }
    
    string getPermuatation(vector<int> &v, int k, int n) {
      string s;
      while (n > 0) {
        int nFactorial = factorial(n-1);
        int i = k / nFactorial;
        k %= nFactorial;
        n -= 1;
        s.push_back(v[i] + '0');
        v.erase(v.begin() + i);
      }
      return s;
    }
    
    string getPermutation(int n, int k) {
      vector<int> v;
      for (int i = 1; i <= n; ++i) v.push_back(i);
      return getPermuatation(v, k-1, n);
    }
};
