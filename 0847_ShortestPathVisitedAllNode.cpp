class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) return 0;
        
        int s = graph.size();
        int endMask = (1<<s) - 1;
        vector<vector<bool>> visited(s, vector<bool>(endMask, false));
        queue<vector<int>> q;
        
        for(int i=0; i<s; i++){
            q.push({i, 1<<i});
            visited[i][1<<i] = true;
        }
        
        int step = 0;
        while(!q.empty()){
            int l = q.size();
            for(int i=0; i<l; i++){
                vector<int> currPair = q.front();
                q.pop();
                int nd = currPair[0];
                int mask = currPair[1];
                for(int nb : graph[nd]){
                    int nextMask = mask | (1<<nb);
                    if(nextMask == endMask) return ++step;
                    
                    if(!visited[nb][nextMask]){
                        visited[nb][nextMask] = true;
                        q.push({nb, nextMask});
                    }
                }
            }
            ++step;
        }
        
        return -1;
    }
};
