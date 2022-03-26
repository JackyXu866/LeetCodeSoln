class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, l = 0, r = nums.size()-1;
        while(l <= r){
            mid = (r-l)/2 + l;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid-1;
        }
        
        return -1;
    }
};
