class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        
        long sum = 0;
        for(int i : target) sum += i;
        int tmp;
        
        while(true){
            tmp = pq.top();
            pq.pop();
            
            sum -= tmp;
            if(sum == 1 || tmp == 1) return true;
            if(sum == 0 || sum > tmp || tmp % sum == 0) return false;
            
            tmp %= sum;     // tmp -= sum but better
            sum += tmp;
            pq.push(tmp);
        }
    }
};
