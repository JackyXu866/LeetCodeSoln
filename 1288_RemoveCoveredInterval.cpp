bool compI(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compI);
        int rt = 0, l = -1, r = -1;
        
        for(const auto& i : intervals){
            // l == i[0] && r < i[1] will take over previous add, just update r
            if(l < i[0] && r < i[1]){
                ++rt;
                l = i[0];
            }
            r = max(r, i[1]);
        }
        
        return rt;
    }
};
