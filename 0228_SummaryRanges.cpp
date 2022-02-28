class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int prev = nums[0], begin = nums[0];
        vector<string> rt;
        for(int i : nums){
            if(i <= prev+1){
                prev = i;
            }
            else{
                rt.push_back(gen(begin, prev));
                begin = i;
                prev = i;
            }
        }
        rt.push_back(gen(begin, prev));
        
        return rt;
    }
    
private:
    string gen(int begin, int prev){
        if(begin == prev) return to_string(begin);
        return to_string(begin)+"->"+to_string(prev);
    }
};
