class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        
        for(int i : nums){
            auto it = lower_bound(lis.begin(), lis.end(), i);
            if(it == lis.end()) lis.push_back(i);
            else *it = i;
        }
        
        return lis.size();
    }
};
