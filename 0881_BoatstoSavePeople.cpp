class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int rt = 0;
        int rb = people.size()-1, b = 0;
        sort(people.begin(), people.end());
        while(rb >= b){
            if(people[rb] + people[b] > limit){
                rt++;
                rb--;
            }
            else{
                rt++;
                rb--;
                b++;
            }
        }
        cout << endl;
        
        return rt;
    }
};
