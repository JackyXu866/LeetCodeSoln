class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), rt = 0;
        for (int i = 0; i < len; i++) {
            int j = i - 1, k = i;
            while (k < len - 1 && s[k] == s[k+1])
                k++;
            
            rt += (k - j) * (k - j + 1) / 2;
            // cout << j << " " << k << ": " << rt << endl
            i = k++;
            
            while (j >= 0 && k < len && s[k] == s[j])
                k++, j--, rt++;
        }
        return rt;
    }
};
