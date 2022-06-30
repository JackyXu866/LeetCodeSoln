class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int med, rt = 0;
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        med = nums[nums.size()/2];
        
        for(int i : nums){
            rt += abs(i-med);
        }
        
        return rt;
    }
};
