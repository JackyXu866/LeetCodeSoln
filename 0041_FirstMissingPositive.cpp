class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0 || nums[i]>nums.size()){
                nums[i] = 0;
            }
        }
        
        int une = nums.size() * -1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0 || nums[i] == une) continue;
            int tmp = max(abs(nums[i])-1, 0);
            if(nums[tmp] > 0)  nums[tmp] *= -1;
            else if(nums[tmp] == 0) nums[tmp] = une;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0) return i+1;
        }
        return nums.size()+1;
    }
};
