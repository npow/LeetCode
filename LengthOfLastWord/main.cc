class Solution {
public:
    int lengthOfLastWord(const char *s) {
        char* pch = strtok((char*)s, " ");
        char* last = NULL;
        while (pch != NULL) {
            last = pch;
            pch = strtok(NULL, " ");
        }
        return last ? strlen(last) : 0;
    }
};
