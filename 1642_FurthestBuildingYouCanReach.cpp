class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if(heights.size() == 0) return 0;
        int prev = heights[0], total = 0;
        priority_queue<int, vector<int>, greater<int>> diff;
        
        for(int i=1; i<heights.size(); i++){
            int tmp = heights[i] - prev;
            prev = heights[i];
            if(tmp <= 0) continue;
            diff.push(tmp);
            if(diff.size() > ladders){
                bricks -= diff.top();
                diff.pop();
                if(bricks < 0) return i-1;
            }
        }
        
        return heights.size()-1;
    }
};
