class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int rt = 0, sum = 0;
        for(auto i : nums){
            sum += i;
            if(sum == k) rt++;
            if(mp.find(sum-k) != mp.end()){
                rt += mp[sum-k];
            }
            ++mp[sum];
        }
        
        return rt;
    }
};
