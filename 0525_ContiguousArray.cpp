class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int rt = 0, curr = 0;
        unordered_map<int, int> hm;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) curr--;
            else curr++;
            
            if(curr==0) rt = i+1;
            if(hm.find(curr) != hm.end()){
                rt = max(rt, i-hm[curr]);
            }
            else hm[curr] = i;
        }
        
        return rt;
    }
};
