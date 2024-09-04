class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int frequency = 0, index = 0, maj = -1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            frequency = 0;  // Reset frequency for each new candidate
            
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] == nums[j]) {
                    frequency++;
                }
            }
            
            // Account for the current element itself
            frequency++;
            
            if (frequency > index) {
                maj = i;
                index = frequency;
            }
        }
        
        return nums[maj];
    }
};
