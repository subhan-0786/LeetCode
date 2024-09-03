class Solution {
public:
    int getLucky(string s, int k) {
        
        int i, j = 0;
        
        vector <int> nums;
        
        for (char c : s) 
        {
            int num = c - 'a' + 1;
            if (num > 9) {
                nums.push_back(num / 10);
                nums.push_back(num % 10);
            } else {
                nums.push_back(num);
            }
        }
        
        int number = 0;
        
        while (k > 0) {
            number = 0;
            
            // Sum all digits
            for (int num : nums) {
                number += num;
            }
            
            // If we've reached a single digit, return it
            if (number < 10) {
                return number;
            }
            
            // Prepare for next iteration
            nums.clear();
            int temp = number;
            while (temp > 0) {
                nums.push_back(temp % 10);
                temp /= 10;
            }
            reverse(nums.begin(), nums.end());
            
            k--;
        }
        
        return number;
        
    }
};