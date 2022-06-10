class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int rt = 1, beg = -1, i=0;
        vector<int> mp(128, -1);
        
        while(i<s.size()){
            if(mp[s[i]] > beg){
                beg = mp[s[i]];
            }
            
            mp[s[i]] = i;
            rt = max(rt, i-beg);
            i++;
        }
        
        return rt;
    }
};
