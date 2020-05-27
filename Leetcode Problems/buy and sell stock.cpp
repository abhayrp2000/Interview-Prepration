class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxP=0;
        
        for(int i=1;i<prices.size();i++){
            for(int j=0;j<i;j++){
                if(prices[j]<prices[i]){
                    maxP=max(prices[i]-prices[j],maxP);
                }
            }
        }
        
        return maxP;
    
        
    }
};