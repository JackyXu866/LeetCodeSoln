class TrieNode{
public:
    TrieNode(){
        for(int i=0; i<26; i++){
            letter[i] = NULL;
        }
        end = false;
    }
    
    TrieNode* letter[26];
    bool end;
};


class WordDictionary {
public:
    WordDictionary() {
        dict = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* pt = dict;
        for(auto c : word){
            if(!pt->letter[c-'a']){
                pt->letter[c-'a'] = new TrieNode();
            }
            pt = pt->letter[c-'a'];
        }
        pt->end = true;
    }
    
    bool search(string word) {
        return search(word, 0, dict);
    }
    

private:
    TrieNode* dict;
    bool search(string& word, int n, TrieNode* nd){
        if(!nd) return false;
        if(n == word.size()) return nd->end;
        if(word[n] != '.'){
            return search(word, n+1, nd->letter[word[n]-'a']);
        }
        for(int i=0; i<26; i++){
            if(search(word, n+1, nd->letter[i])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
