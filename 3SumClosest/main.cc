class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return target;
        sort(num.begin(), num.end());
        int minSum = std::numeric_limits<int>::max();
        int minDiff = minSum;
        for (int i = 0; i < num.size() - 2; ++i) {
            int a = num[i];
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int b = num[j];
                int c = num[k];
                if (a + b + c == target) {
                    return target;
                } else {
                    int diff = abs(a + b + c - target);
                    if (diff < minDiff) {
                        minSum = a + b + c;
                        minDiff = diff;
                    }
                    if (a + b + c > target) {
                        --k;
                    } else {
                        ++j;
                    }
                }
                
            }
        }
        return minSum;
    }
};

