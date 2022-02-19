class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rt = 0;
        for(auto i : accounts){
            int tmp = 0;
            for(auto j : i){
                tmp += j;
            }
            rt = max(rt, tmp);
        }
        return rt;
    }
};
