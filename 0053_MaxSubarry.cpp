class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rt = INT_MIN;
        int curr = 0;
        
        for(int i : nums){
            curr += i;
            rt = max(rt, curr);
            
            curr = max(0, curr);
        }
        return rt;
    }
};
