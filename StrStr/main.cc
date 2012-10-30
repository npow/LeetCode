class Solution {
public:
    static bool matches(char *h, char *n) {
        while (*h != '\0' && *n != '\0') {
            if (*h != *n) return false;
            h++;
            n++;
        }
        return '\0' == *n;
    }
    char *strStr(char *haystack, char *needle) {
        if (!needle || *needle == '\0') return haystack;
        if (!haystack || *haystack == '\0') return NULL;
        char *h = haystack, *n = needle;
        int hash_n = 0, hash_h = 0;
        while (*n != '\0') {
            hash_n += (int)*n;
            n++;
            if (!h || *h == '\0') return NULL;
            hash_h += (int)*h;
            h++;
        }
        do {
            if (hash_n == hash_h && Solution::matches(haystack, needle)) return haystack;
            hash_h -= (int)*haystack;
            haystack++;
            hash_h += (int)*h;
            h++;
        } while (*h != '\0');
        return NULL;
    }
};
