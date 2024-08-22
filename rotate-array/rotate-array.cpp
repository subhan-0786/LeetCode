class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

// This code also works for most pf the cases but not all

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n; // if k > size

//         if (k == 0) return; 
        
//         int i, j;

//         for (i = 0; i <= k; i++) {
//             int temp = nums[i];
//             for (j = 0; j < n-1; j++)
//                 nums[j] = nums[j+1];
//             nums[j] = temp;
//         }
//     }
// };
