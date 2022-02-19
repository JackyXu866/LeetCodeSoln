class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> mp;
        set<pair<int, int>> st;
        for(auto i:nums){
            if(mp.find(i+k) != mp.end()) st.insert(make_pair(i, i+k));
            if(mp.find(i-k) != mp.end()) st.insert(make_pair(i-k, i));
            mp.insert(i);
        }
        
        return st.size();
    }
};
