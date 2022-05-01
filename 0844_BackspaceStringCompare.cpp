class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1, j=t.size()-1;
        while(i>=0 && j>=0){
            if(s[i] == '#' || t[j] == '#'){
                if(s[i] == '#') i = countBack(s, i);
                if(t[j] == '#') j = countBack(t, j);
            }
            else{    
                if(s[i] != t[j]) return false;
                --i; --j;
            }
        }
        
        while(i>=0&&s[i]=='#')
            i = countBack(s, i);
        while(j>=0&&t[j]=='#')
            j = countBack(t, j);
        if(i >= 0 || j>= 0) return false;
        
        return true;
    }
    
private:
    int countBack(string& a, int n){
        int rt = 0;
        while(n-rt >= 0 && a[n-rt] == '#') ++rt;
        n -= rt;
        while(n >= 0 && rt>0){
            if(a[n] == '#') rt++, n--;
            else n--, rt--;
        }
        return n;
    }
};
