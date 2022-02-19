bool largerEnd(vector<int>& a, vector<int>&b){
    return a[1] < b[1];
}

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), largerEnd);
        int rt = 0, arr;
        for(vector<int>& i:points){
            if(rt == 0 || arr < i[0]){
                rt ++;
                arr = i[1];
            }
        }
        return rt;
    }

};
