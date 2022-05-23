class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int zero, one;
        
        for(auto& s : strs){
            zero = 0, one = 0;
            for(auto c : s){
                if(c == '0') zero++;
                if(c == '1') one++;
            }
            
            for(int i = m; i>=zero; i--){
                for(int j = n; j>=one; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
                }
            }
        }
        
        return dp[m][n];
    }
};
