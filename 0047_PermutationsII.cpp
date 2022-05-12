class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> rt;
        sort(nums.begin(), nums.end());
        recur(nums, rt, 0);
        return rt;
    }
    
private:
    
    void recur(vector<int>& nums, vector<vector<int>>& rt, int i = 0){
        if(i == nums.size()-1){
            rt.push_back(nums);
            return;
        }
        
        for(int j = i; j<nums.size(); j++){
            if(j!=i && nums[j] == nums[i]) continue;
            swap(nums[i], nums[j]);
            recur(nums, rt, i+1);
        }
        
        // restore, for pass by reference
        sort(nums.begin()+i, nums.end());
    }
};
