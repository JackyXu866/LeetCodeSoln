class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> w2(26);
        vector<string> rt;
        for(string& w : words2){
            vector<int> tmp = ct(w);
            for(int i=0; i<26; i++) w2[i] = max(w2[i], tmp[i]);
        }
        
        int i;
        for(string& w : words1){
            vector<int> tmp = ct(w);
            for(i=0; i<26; i++){
                if(tmp[i] < w2[i]) break;
            }
            if(i >= 25) rt.push_back(w);
        }
        
        return rt;
    }
    
private:
    vector<int> ct(string& w){
        vector<int> rt(26);
        for(char c : w){
            rt[c-'a']++;
        }
        return rt;
    }
};
