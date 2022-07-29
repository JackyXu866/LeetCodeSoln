class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p = normalize(pattern);
        vector<string> rt;
        for(auto& w : words){
            if(normalize(w) == p) rt.push_back(w);
        }
        
        return rt;
    }
    
private:
    string normalize(string s){
        unordered_map<char, int> mp;
        for(auto c : s){
            if(mp.find(c) == mp.end()) mp[c] = mp.size();
        }
        for(int i=0; i<s.size(); i++) s[i] = 'a'+mp[s[i]];
        return s;
    }
};
