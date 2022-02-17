class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, maxP = -1;
        for(int i=0; i<prices.size(); i++){
            minP = min(prices[i], minP);
            maxP = max(prices[i]-minP, maxP);
        }
        
        return maxP;
    }
};
