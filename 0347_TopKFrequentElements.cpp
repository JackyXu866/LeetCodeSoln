class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i : nums){
            ++mp[i];
        }
        
        for(auto& i : mp){
            pq.push(i.second);
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> rt;
        int val = pq.top();
        for(auto& i : mp){
            if(i.second >= val) rt.push_back(i.first);
        }
        
        return rt;
    }
};
