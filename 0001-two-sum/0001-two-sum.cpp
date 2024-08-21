class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        vector<int> index;
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i+1; j < nums.size(); j++)
                if ((nums[i] + nums[j]) == target)
                    break;
            if (j != nums.size())
                break;
        }
                
        
        if (i != nums.size())
        {
            index.push_back(i);
            index.push_back(j);
        }
        return index;
    }
};