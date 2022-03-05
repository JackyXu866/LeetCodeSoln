class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxE = 0;
        for(int i:nums){
            mp[i] += i;
            maxE = max(maxE, i);
        }
        
        vector<int> dp(maxE+1, 0);
        dp[1] = (mp.find(1) == mp.end())? 0 : mp[1];
        
        for(int i=2; i<=maxE; i++){
            dp[i] = max(dp[i-1], dp[i-2]+((mp.find(i) == mp.end())? 0 : mp[i]));
        }
        
        return dp[maxE];
    }
};
