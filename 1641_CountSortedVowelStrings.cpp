class Solution {
public:
    int countVowelStrings(int n) {
        // C^(n+4)_4 -> put 4 separation mark in n+4 position
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }

};
