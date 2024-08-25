class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minimum = prices[0];
        
        // NOW, MY MAGIC LOOP
        
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - minimum;  
            minimum = min(minimum, prices[i]);  
            maxProfit = max(maxProfit, profit); 
        }
        return maxProfit;
    }
};