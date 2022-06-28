class Solution {
public:
    int minDeletions(string& s) {
        int freq[26] = {0};
        
        for(const char c : s){
            ++freq[c-97];
        }
        
        sort(begin(freq), end(freq), greater());
        
        int rt = freq[0], prev = freq[0];
        for(int i = 1; i < 26 && freq[i] > 0 && prev > 0; i++){
            prev = min(freq[i], prev-1);
            rt += prev;
        }
        
        return s.size() - rt;
    }
};
