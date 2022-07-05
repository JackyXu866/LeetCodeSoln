class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int rt = 0;
        
        for(int i: nums){
            if(s.find(i) == s.end()) continue;
            s.erase(i);
            int less = i-1, more = i+1;
            while(s.find(less) != s.end()) s.erase(less), less--;
            while(s.find(more) != s.end()) s.erase(more), more++;
            
            rt = max(rt, more-less-1);
        }
        
        return rt;
    }
};
