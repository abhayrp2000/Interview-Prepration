class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n=prices.size();
        for(int i = 1; i < n; i++) {
            int j = i - 1;
            
            if(prices[i] - prices[j]>0) {
                maxProfit += (prices[i] - prices[j]);
            }
        }
        
        return maxProfit;
        
    }
};