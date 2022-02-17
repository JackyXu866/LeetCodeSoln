class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        if(rowIndex >= 0) dp.push_back({1});
        for(int i=1; i<=rowIndex; i++){
            vector<int> tmp = {1};
            for(int j=1; j<i; j++){
                tmp.push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            tmp.push_back(1);
            dp.push_back(tmp);
        }
        
        return dp[rowIndex];      
    }
};
