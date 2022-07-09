class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int rt =  recur(houses, cost, m, n, target, 0, 0);
        return rt < MAX ? rt : -1;
    }
    
private:
    int MAX = 1000001;
    int dp[101][21][101] = {};
    
    int recur(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int prev) {
        if(i == m && target == 0) return 0; // finish painting
        if(m == i || target < 0) return MAX;    // cannot solve
        
        if(dp[i][prev][target]) return dp[i][prev][target];
        
        int rt = MAX;
        if(!houses[i]){  // assign new color
            for(int c=1; c<=n; c++){
                rt = min(rt, recur(houses, cost, m, n, target-(c!=prev), i+1, c) + cost[i][c-1]);
            }
        }
        else rt = recur(houses, cost, m, n, target-(houses[i]!=prev), i+1, houses[i]);
        
        dp[i][prev][target] = rt;
        return rt;
    }
    
};
