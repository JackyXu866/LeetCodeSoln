class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int rt = n;

        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        for(int i=0; i<v.size(); i++){
            int left = v[i];
            int right = left + n - 1;
            int diff = upper_bound(v.begin(), v.end(), right) - v.begin() - i;
            rt = min(rt, n-diff);
        }

        return rt;
    }
};
