class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, p, mid;
        while(l <= r){
            p = l + (r-l)/2;
            if(nums[p] == target) return p;
            if(nums[p] < nums[r]){
                r = p;
            }
            else{
                l = p+1;
            }
        }
        
        if(p == 0){
            l = 0;
            r = nums.size()-1;
        }
        else if(nums[0] <= target){
            l = 0;
            r = p-1;
        }
        else{
            l = p;
            r = nums.size()-1;
        }
        
        while(l <= r){
            mid = (r-l)/2 + l;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        
        return -1;
    }
};
