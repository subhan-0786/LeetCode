class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector <int> output;
        
        
        for (int i = 0; i < matrix.size();  i++)
        {
            int minimum = matrix[i][0];
            int minindex = 0;
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (minimum > matrix[i][j])
                {
                    minimum = matrix[i][j];
                    minindex = j;
                }
                    
            }
            
            bool isLucky = true;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][minindex] > minimum) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) {
                output.push_back(minimum);
            }
        }
        
        return output;         
        
    }
};