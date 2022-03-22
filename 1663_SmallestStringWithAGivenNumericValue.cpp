class Solution {
public:
    string getSmallestString(int n, int k) {
        string rt = "";
        for(int i=1; i<=n; i++){
            if(k-26 >= n-i){
                rt += 'z';
                k -= 26;
            }
            else if(k > n-i){
                rt += char(k-n+i+96);
                k = n-i;
            }
        }
        reverse(rt.begin(), rt.end());
        return rt;
    }
};
