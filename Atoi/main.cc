class Solution {
public:
    int atoi(const char *str) {
        if (!str || *str == '\0') return 0;
        int sign = -2;
        int x = 0;
        while (sign == -2 && *str != '\0' && !isdigit(*str)) {
            if (*str == '+') {
                sign = 1;
            } else if (*str == '-') {
                sign = -1;
            }
            str++;
        }
        sign = (sign == -2 ? 1 : sign);
        while (isdigit(*str)) {
            x = 10*x + (*str - '0');
            str++;
        }
        return sign * x;
    }
};
