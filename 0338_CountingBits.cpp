class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1; i<=n; i++){
            if(i%2) dp.push_back(dp[i/2]+1);
            else dp.push_back(dp[i/2]);
        }
        
        return dp;
    }
};
