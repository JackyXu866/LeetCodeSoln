class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[27] = {0};
        for(int i=0; i<s.size(); i++){
            last[s[i]-97] = i;
        }
        int send = last[s[0]-97], num = 1;
        vector<int> rt;
        for(int i=1; i<s.size(); i++){
            if(i > send){
                rt.push_back(num);
                num = 0;
            }
            send = max(send, last[s[i]-97]);
            ++num;
        }
        if(num != 0) rt.push_back(num);
        
        return rt;
    }
};
