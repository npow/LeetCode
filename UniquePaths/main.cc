class Solution {
public:
    int uniquePaths(int m, int n) {
        static map<int, int> hash;
        int h = 1000*m + n;
        if (hash.find(h) == hash.end()) {
            if (m < 0 || n < 0) return 0;
            else if (m == 1) return 1;
            else if (n == 1) return 1;
            else hash[h] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        }
        return hash[h];
    }
};
