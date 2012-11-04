ass Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > v = vector<vector<int> >(word1.length()+1, vector<int>(word2.length()+1));
        for (int i = 0; i < word1.length()+1; ++i) {
            for (int j = 0; j < word2.length()+1; ++j) {
                if (i == 0) {
                    v[i][j] = j;
                } else if (j == 0) {
                    v[i][j] = i;
                } else {
                    if (word1[i-1] == word2[j-1]) {
                        v[i][j] = v[i-1][j-1];
                    } else {
                        v[i][j] = 1 + min(v[i-1][j], min(v[i][j-1], v[i-1][j-1]));
                    }
                }
            }
        }
        return v[word1.length()][word2.length()];
    }
};
