class Solution {
public:

    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);

        // Count remainders
        for (int num : arr) {
            int rem = ((num % k) + k) % k; // Ensures positive remainders
            remainderCount[rem]++;
        }

        // Check pairs
        if (remainderCount[0] % 2 != 0) return false; // Special case: remainder 0 should have even count

        for (int i = 1; i <= k / 2; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }

        return true;
    }


};