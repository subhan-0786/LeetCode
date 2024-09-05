class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (m + n) * mean;  // Total required sum for all rolls
        int sumRolls = 0;
        
        
        for (int i = 0; i < m; i++) {
            sumRolls += rolls[i];
        }
        
        int remainder = totalSum - sumRolls;  

        // If the remainder can't be divided into valid rolls (EACH BETWEEN 1 and 6)
        if (remainder < n || remainder > 6 * n) {
            return {};  
        }
        
        vector<int> result(n, remainder / n);  // Fill the result with base values
        
        int extra = remainder % n;  // Distribute the remaining extra points

        // Distribute the extra points to the first few rolls
        for (int i = 0; i < extra; i++) {
            result[i]++;
        }
        
        return result;
    }
};
