class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
           return a.size() < b.size(); 
        });
        
        int rt = 0;
        unordered_map<string, int> dp;
        for(auto& w : words){
            for(int i=0; i<w.size(); i++){
                string tmp = w.substr(0, i) + w.substr(i+1);
                int val;
                if(dp.find(tmp) == dp.end()) val = 1;
                else val = dp[tmp] + 1;
                dp[w] = max(dp[w], val);
            }
            rt = max(rt, dp[w]);
        }
        
        return rt;
    }
};
