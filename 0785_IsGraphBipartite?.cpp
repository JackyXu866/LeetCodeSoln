class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        
        queue<int> q;
        
        for(int i=0; i<graph.size(); i++){
            if(color[i] != 0) continue;
            
            color[i] = 1;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int adj : graph[curr]){
                    if(color[adj] == 0){
                        q.push(adj);
                        color[adj] = -color[curr];
                    }
                    else if(color[adj] == color[curr]) return false;
                }
            }
        }
        
        return true;
    }
};
