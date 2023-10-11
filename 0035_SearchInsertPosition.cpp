class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        int mid;

        if(target > nums[end]) return end+1;
        while(beg < end){
            mid = beg+(end-beg)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid;
            else beg = mid+1;
        }

        return beg;
    }
};
