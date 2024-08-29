class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        long long int original = x;
        long long int reversed = 0;

        while (x > 0) {
            int digit = x % 10;   
            reversed = reversed * 10 + digit; 
            x /= 10;                    
        }

        return original == reversed;  
    }
};
