class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> firstOccurrence(32, -1); // Array to track the first occurrence of each bitmask
        int maxLength = 0;
        int mask = 0;
        firstOccurrence[0] = 0; // Initialize for the case where the substring from the start has even counts of vowels

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // Update the mask if the character is a vowel
            switch (c) {
                case 'a': mask ^= 1 << 0; break; // 'a' -> bit 0
                case 'e': mask ^= 1 << 1; break; // 'e' -> bit 1
                case 'i': mask ^= 1 << 2; break; // 'i' -> bit 2
                case 'o': mask ^= 1 << 3; break; // 'o' -> bit 3
                case 'u': mask ^= 1 << 4; break; // 'u' -> bit 4
            }

            // Check if this bitmask has been seen before
            if (firstOccurrence[mask] != -1) {
                maxLength = max(maxLength, i + 1 - firstOccurrence[mask]);
            } else {
                // Record the first occurrence of this bitmask
                firstOccurrence[mask] = i + 1;
            }
        }
        return maxLength;
    }
};
