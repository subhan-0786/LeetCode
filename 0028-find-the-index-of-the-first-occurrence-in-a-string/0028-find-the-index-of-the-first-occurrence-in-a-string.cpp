class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  // If needle is empty, return 0

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            // Check if the substring of haystack starting from i matches needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;  // Found the first occurrence of needle
            }
        }

        return -1;  
    }
};
