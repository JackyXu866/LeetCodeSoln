class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, rem, rt = -1;
        for(auto i : nums){
            sum += i;
        }
        
        rem = sum - x;
        if(rem == 0) return nums.size();
        else if(rem < 0) return -1;
        
        sum = 0;
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            
            j = max(j, i);
            for(; j<nums.size() && sum < rem; j++)
                sum += nums[j];
            
            if(sum == rem) rt = max(rt, j-i);
            
            sum -= nums[i];
        }
        
        if(rt == -1) return -1;
        return nums.size()-rt;
    }
};

