class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0; 
        
        int rt = 0;
        for(int i=0; i<nums.size(); i++){
            int j = i+2;
            if(j >= nums.size()) break;
            int diff = nums[i+1] - nums[i];
            while(j < nums.size()){
                if(nums[j] - diff != nums[j-1]) break;
                ++rt;
                ++j;
            }
        }
        
        return rt;
    }
};
