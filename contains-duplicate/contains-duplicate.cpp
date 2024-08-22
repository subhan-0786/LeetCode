
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array first

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;  // Duplicate found
            }
        }
        
        return false;  // No duplicates found
    }
};
