class Solution {
public:
    string addBinary(string A, string B) {
        
        // Step 1: Pad the shorter string with zeros
        
        int lenA = A.size();
        int lenB = B.size();
        if (lenA < lenB) A.insert(0, lenB - lenA, '0');
        else if (lenB < lenA) B.insert(0, lenA - lenB, '0');
        
        // Step 1 DONE

        string result = "";  // To store the result
        int carry = 0;            // Initialize carry to 0

        // Step 2: Add binary numbers from right to left
        
        for (int i = A.size() - 1; i >= 0; --i) {
            int sum = (A[i] - '0') + (B[i] - '0') + carry;  // Convert char to int and add
            if (sum == 0) {
                result += '0';
                carry = 0;
            } else if (sum == 1) {
                result += '1';
                carry = 0;
            } else if (sum == 2) {
                result += '0';  // 2 means 10 in binary, so append '0' and set carry to 1
                carry = 1;
            } else if (sum == 3) {
                result += '1';  // 3 means 11 in binary, so append '1' and set carry to 1
                carry = 1;
            }
        }
        
        // DONE, Easy Step

        // Step 3: Append final carry if needed
        if (carry == 1) {
            result += '1';
        }

        // Step 4: Reverse the result as it was computed from right to left
        reverse(result.begin(), result.end());
        return result;
    }

};