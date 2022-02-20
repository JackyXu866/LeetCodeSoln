class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int rt = 0, l = -1, r = -1;
        
        for(const auto& i : intervals){
            // l == i[0] && r < i[1] will take over previous add, just update r
            if(l < i[0] && r < i[1]){
                ++rt;
                l = i[0];
            }
            if(r < i[1]) r = i[1];
        }
        
        return rt;
    }
};
