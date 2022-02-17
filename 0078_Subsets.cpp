class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rt;
        rt.push_back({});
        for(auto i : nums){
            int s = rt.size();
            for(int j = 0; j<s; j++){
                vector<int> tmp (rt[j]);
                tmp.push_back(i);
                rt.push_back(tmp);
            }
        }
        return rt;
    }
};
