class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int frequency=0;
        int size = nums.size();
        int array[size];
        
        // for (int i=0; i<nums.size(); i++)
        //    if (nums[i] == 0)
        //        frequency++;
        int j = 0;
        
        for (int i =0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                array[j++] = nums[i];
            }
        }
        
        for (int i = j; i < nums.size(); i++)
        {
            array[i] = 0;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i]= array[i];
        }
        
    }
};