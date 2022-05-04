class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int rt = 0;
        
        for(const int& i : nums){
            if(mp.find(i) != mp.end() && mp[i] > 0){
                rt++;
                --mp[i];
            }
            else mp[k-i]++;
        }
        
        return rt;
    }
};
