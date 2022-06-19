class Trie{
private:
    Trie* alph[26];
    vector<string> suggest;
    
public:
    void addWord(const string& s){
        Trie* root = this;
        root->suggest.push_back(s);
        for(const char c : s){
            if(!root->alph[c-97]){
                root->alph[c-97] = new Trie();   
            }
            root = root->alph[c-97];
            root->suggest.push_back(s);
        }
    }
    
    vector<string> suggestWord(const string& s, int size){
        Trie* root = this;
        for(const char c : s){
            if(root->alph[c-97]){
                root = root->alph[c-97];
            }
            else return {};
        }
        
        vector<string>& rt = root->suggest;
        if(rt.size() >= size) return vector<string>(rt.begin(), rt.begin()+size);
        return rt;
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* r = new Trie();
        sort(products.begin(), products.end());
        for(const string& s : products){
            r->addWord(s);
        }
        
        vector<vector<string>> rt;
        string tmp = "";
        for(const char c : searchWord){
            tmp.push_back(c);
            rt.push_back(r->suggestWord(tmp, 3));
        }
        
        return rt;
    }
};
