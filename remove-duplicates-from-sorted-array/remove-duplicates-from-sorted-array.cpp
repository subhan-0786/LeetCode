#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case: empty array

        int uniqueIndex = 0; // Index of the last unique element

        for (int currentIndex = 1; currentIndex < nums.size(); currentIndex++) {
            if (nums[currentIndex] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[currentIndex];
            }
        }

        return uniqueIndex + 1; // Number of unique elements
    }
};
