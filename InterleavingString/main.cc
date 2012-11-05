class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool> > visited = vector<vector<bool> >(s1.size(), vector<bool>(s2.size(), false));
        return isInterleave(s1, s2, s3, 0, 0, 0, visited);
    }
    bool isInterleave(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<bool> >& visited) {
        if (j == s2.length()) return s1.substr(i) == s3.substr(k);
        if (i == s1.length()) return s2.substr(j) == s3.substr(k);
        if (visited[i][j]) return false;
        
        if ((s1[i] == s3[k] && isInterleave(s1, s2, s3, i+1, j, k+1, visited)) ||
            (s2[j] == s3[k] && isInterleave(s1, s2, s3, i, j+1, k+1, visited))) {
            return true;   
        }

        visited[i][j] = true;
        return false;
    }
};
