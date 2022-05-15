class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);
        
        for(auto& i : times){
            adj[i[0]].push_back({i[2], i[1]});
        }
                
        int rt = 0;
        queue<int> q;
        q.push(k);
        dist[k] = 0;
        while(!q.empty()){
            int i = q.size();
            for(int j=0; j<i; j++){         
                int tmp = q.front();
                q.pop();
                for(auto& x : adj[tmp]){
                    if(dist[x.second] > dist[tmp] + x.first){
                        dist[x.second] = dist[tmp] + x.first;
                        q.push(x.second);
                    }
                }
            }
        }
        
        for(int i = 1; i<n+1; i++){
            if(dist[i] == INT_MAX) return -1;
            rt = max(dist[i], rt);
        }
        
        return rt;
    }
};
