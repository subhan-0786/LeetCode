class Solution {
public:
    static bool compare(const string& a, const string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int i = 0; i < nums.size(); i++) {
            numStrings.push_back(to_string(nums[i]));
        }
        
        sort(numStrings.begin(), numStrings.end(), compare);
        
        string output = "";
        for (const string& numString : numStrings) {
            output += numString;
        }
        
        // Handle case where all numbers are zero
        if (output[0] == '0') return "0";
        
        return output;
    }
};