// Hash_Map: Time O(n), Space O(n)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(int i : nums){
//             ++mp[i];
//             if(mp[i] > nums.size()/2) return i;
//         }
        
//         return -1;
//     }
// };

// Sort: Time O(nlogn), Space O(1/n) depends on sort
// class Solution {
//     public:
//         int majorityElement(vector<int>& nums) {
//             sort(nums.begin(), nums.end());
//             return nums[nums.size()/2];
//         }
// };

// Boyer-Moore Algo: Time O(1), Space O(1)
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int val, num = 0;
            for(const int& i : nums){
                if(num == 0) val = i;
                if(val == i) ++num;
                else --num;
            }
            
            return val;
        }
};
