class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rt = 0;
        for(int i=1; i<prices.size(); i++){
            rt += max(0, prices[i]-prices[i-1]);
        }
        
        return rt;
    }
};
