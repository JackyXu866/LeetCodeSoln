class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int h = numbers.size()-1, l = 0;
        
        while(h > l){
            int sum = numbers[h]+numbers[l];
            if(sum == target) return {l+1, h+1};
            else if(sum < target) l++;
            else h--;
        }
        
        return {};
    }
};
