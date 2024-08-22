class Solution {
public:
    int findComplement(int num) 
    {
        int result = 0;
        int power = 0;

        while (num > 0) {
            // Check the last bit of num, flip it, and add it to the result
            int bit = (num % 2 == 0) ? 1 : 0;
            result += bit * pow(2, power);
            
            // Move to the next bit
            num /= 2;
            power++;
        }

        return result;
    }
};