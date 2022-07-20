struct Word {
    const string& w;
    int i;
    Word(const string& w, int i): w(w), i(i) {}
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Word> ns[26];
        // place the initial/beginning letter to vector
        for(auto& i : words){
            ns[i[0]-'a'].push_back(Word(i, 0));
        }
        
        int rt = 0;
        for(char c : s){
            vector<Word> w = ns[c-'a'];
            ns[c-'a'].clear();
            // update letter index
            for(auto& i : w){
                i.i++;
                if(i.i == i.w.size()) {rt++; continue;}
                ns[i.w[i.i]-'a'].push_back(i);
            }
        }
        
        return rt;
    }
};
