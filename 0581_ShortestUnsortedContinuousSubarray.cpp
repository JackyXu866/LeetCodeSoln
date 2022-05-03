class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int _max = INT_MIN, _min = INT_MAX, _beg = -1, _end = -2;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < _max) _end = i;
            _max = max(_max, nums[i]);
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > _min) _beg = i;
            _min = min(_min, nums[i]);
        }
        
        return _end-_beg+1;
    }
};
