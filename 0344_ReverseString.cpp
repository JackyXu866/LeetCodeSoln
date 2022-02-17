class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> temp;
        int si = s.size();
        for(uint i=0; i<si; i++){
            temp.push_back(s.back());
            s.pop_back();
        }
        s = temp;
    }        
};
