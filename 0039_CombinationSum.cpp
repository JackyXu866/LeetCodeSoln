class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rt;
        vector<int> nums;
        findSum(candidates, nums, target, rt, 0);
        return rt;
    }
private:
    void findSum(vector<int>& candidates, vector<int>& nums, int target, vector<vector<int>>& rt, int l){
        if(target < 0) return;
        if(target == 0) {
            rt.push_back(nums);
            return;
        }
        
        for(int i=l; i<candidates.size(); i++){
            nums.push_back(candidates[i]);
            findSum(candidates, nums, target-candidates[i], rt, i);
            nums.pop_back();
        }
    }
};
