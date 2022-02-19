class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int win = 0;
        pair<int, int> types (-1, -1);
        
        for(int i=fruits.size()-1; i>=0; i--){
            if(win > i) return win;
            for(int j=i; j>=0; j--){
                if(types.first == -1){
                    types.first = fruits[j];
                }
                else if(types.first != fruits[j] && types.second == -1){
                    types.second = fruits[j];
                }
                else if(types.first != fruits[j] && types.second != fruits[j]){
                    if(win < i-j) win = i-j;
                    break;
                }
                if(j==0 && win<i+1) return i+1;
            }
            types = make_pair(-1, -1);
        }
        
        return win;
    }
};
