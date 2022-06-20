class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string_view> st(words.begin(), words.end());
        
        for(string_view w : st){
            for(int i=1; i<w.size(); i++){
                st.erase(w.substr(i));
            }
        }
        
        int rt = 0;
        for(auto w : st) rt += w.size()+1;
        return rt;
    }
};
