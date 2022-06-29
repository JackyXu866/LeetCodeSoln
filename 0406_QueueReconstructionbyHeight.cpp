class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> rt;
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        for(vector<int>& i : people){
            list<vector<int>>::iterator it = std::next(rt.begin(), i[1]);
            rt.insert(it, i);
        }
        
        return vector<vector<int>>(rt.begin(), rt.end());
    }
};
