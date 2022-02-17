class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev, count = 0;
        for(int i=0; i<nums.size(); i++){
            prev = nums[i];
            count ++;
            if(i+1<nums.size() && nums[i+1] == prev){
                count++;
                i++;
            }
            auto j = nums.begin()+i+1;
            while(j != nums.end() && *j == prev){
                j = nums.erase(j);
            }
        }
        
        return count;
    }
};
