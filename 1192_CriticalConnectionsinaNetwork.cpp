class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        rank.resize(n, -2);
        s = n;
        for(auto& i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        dfs(0, 0);
        return rt;
    }
    
private:
    vector<vector<int>> adj;
    vector<int> rank;
    vector<vector<int>> rt;
    int s;
    
    int dfs(int n, int r){
        if(rank[n] >= 0) return rank[n];
        
        rank[n] = r;
        int minR = r;
        
        for(auto nei : adj[n]){
            if(rank[nei] == r-1 || rank[nei] == s) continue;
            
            int nr = dfs(nei, r+1);
            minR = min(nr, minR);
            
            if(nr > r) rt.push_back({n, nei});
        }
        rank[n] = s;
        
        return minR;
    }
};
