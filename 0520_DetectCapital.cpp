class Solution {
public:
    bool detectCapitalUse(string& word) {
        int count = 0;
        for(auto c:word){
            if(isupper(c)){
                count ++;
            }
        }
        return count == 0 || (count == 1 && isupper(word[0])) || count==word.length();
    }
};
