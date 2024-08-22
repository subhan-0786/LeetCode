class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int find;
        for (int i=0; i < nums.size(); i++)
        {
            int check = 0;
            find = nums[i];
            
            for (int j = 0; j < nums.size(); j++)
                if (nums[j] == find)
                    check++;
            if (check < 2)
                break;
            
        }
        
        return find;
        
    }
};