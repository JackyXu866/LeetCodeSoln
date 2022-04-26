class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost = 0, edge = 0;
        
        vector<bool> visited(n);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        while(edge < n){
            int curr = -1, currEdge = INT_MAX;
            
            for(int i=0; i<n; i++){
                if(!visited[i] && currEdge > minDist[i]){
                    currEdge = minDist[i];
                    curr = i;
                }
            }
                
            cost += currEdge;
            edge++;
            visited[curr] = true;

            for(int i=0; i<n; i++){
                int weight = abs(points[curr][0] - points[i][0])
                        + abs(points[curr][1] - points[i][1]);
                if(!visited[i] && minDist[i] > weight) minDist[i] = weight;
            }
        }
        
        return cost;
    }
};
