class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;  // This will keep track of the consistent words

        // Loop through each word in the words list
        for (int i = 0; i < words.size(); i++) {
            bool isConsistent = true;  // Assume the word is consistent at the start

            // Check each letter in the current word
            for (int j = 0; j < words[i].length(); j++) {
                // If a letter in the word is not in the allowed string
                if (allowed.find(words[i][j]) == string::npos) {
                    isConsistent = false;  // Mark the word as inconsistent
                    break;  // No need to check further, break out of the loop
                }
            }

            // If the word is consistent, increase the result count
            if (isConsistent) {
                result++;
            }
        }

        return result;  // Return the total number of consistent words
    }
};
