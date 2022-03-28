class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] == target) return 1;
            if(nums[l] < nums[mid]){
                if(target < nums[mid] && target >= nums[l]){
                    r = mid-1;
                }
                else{
                    l = mid + 1;
                }
            }
            else if(nums[r] > nums[mid]){
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(nums[l] == nums[mid]) l++;
                if(nums[r] == nums[mid]) r--;
            }
        }
        
        return nums[l] == target;
    }
};
