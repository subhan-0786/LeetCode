class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (int c : chalk) {
            total += c;
        }
        
        k %= total;  // Reduce k to avoid unnecessary iterations

        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // unreachable, but required to avoid compiler warnings
    }
};
