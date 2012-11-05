    string minWindow(string S, string T) {
        int hasFound[256] = {0};
        int needToFind[256] = {0};
        int numMatch = 0;
        int minLen = std::numeric_limits<int>::max();
        int iMin = 0;
        for (int i = 0; i < T.size(); ++i) {
            needToFind[T[i]]++;
        }
        for (int i = 0, j = 0; j < S.size(); ++j) {
            if (!needToFind[S[j]]) continue;
            hasFound[S[j]]++;
            if (hasFound[S[j]] <= needToFind[S[j]]) {
                numMatch++;
            }
            if (numMatch == T.size()) {
                while (i <= j) {
                    if (!needToFind[S[i]] || hasFound[S[i]] > needToFind[S[i]]) {
                        if (hasFound[S[i]] > needToFind[S[i]]) {
                            hasFound[S[i]]--;
                        }
                        i++;
                    } else {
                        break;
                    }
                }
                if (j - i + 1 < minLen) {
                    iMin = i;
                    minLen = j - i + 1;
                }
            }
        }
        return minLen <= S.size() ? S.substr(iMin, minLen) : "";
    }
