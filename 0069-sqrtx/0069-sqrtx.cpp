class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long long left = 1;
        long long right = x;
        long long result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == x) return mid;
            
            if (square < x) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};