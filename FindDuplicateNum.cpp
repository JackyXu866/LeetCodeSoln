class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size();
        
        while(low <= high){
            int tmp = (high + low) /2;
            int count = 0;
            for(auto i:nums){
                if(i <= tmp) count ++;
            }
            if(count > tmp) high = tmp-1;
            else low = tmp+1;
        }
        
        return low;
    }
    
};
