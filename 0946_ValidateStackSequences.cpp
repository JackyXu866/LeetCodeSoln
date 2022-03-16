class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int p = 0;
        auto itr = pushed.begin();
        while(itr != pushed.end() && p < popped.size()){
            cout << p << endl;
            if(*itr == popped[p]){
                itr = pushed.erase(itr);
                ++p;
                if(itr == pushed.begin()) continue;
                else --itr;
            }
            else{
                ++itr;
            }
        }
        
        return p == popped.size();
    }
};
