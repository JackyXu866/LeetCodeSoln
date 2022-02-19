class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> rt;
        if(p.size() > s.size()) return rt;
        
        int ps[26] = {};
        for(auto c:p){
            ps[c-'a']++;
        }
                
        for(int i=0; i<=s.size()-p.size(); i++){
            int tmp[26] = {};
            for(int j=i; j<i+p.size(); j++){
                tmp[s[j]-'a'] ++;
            }
            int j = 0;
            for(; j<26; j++){
                if(ps[j] != tmp[j]) break;
            }
            if(j == 26) rt.push_back(i);
        }
        
        return rt;
    }
};
