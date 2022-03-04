class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[102] = {(double)poured};
        
        for(int i=1; i<=query_row; i++){
            for(int j=i; j>=0; j--){
                double tmp = max((dp[j]-1.0)/2.0, 0.0);
                dp[j] = tmp;
                dp[j+1] += tmp;
            }
        }
        
        return min(1.0, dp[query_glass]);
    }
};
