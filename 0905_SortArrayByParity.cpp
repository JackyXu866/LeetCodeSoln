class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++)
            if (nums[j] % 2 == 0) swap(nums[i++], nums[j]);
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int i=0, j=nums.size()-1;
//         while(i < j){
//             while(i<nums.size() && nums[i]%2 == 0) i++;
//             while(j > 0 && nums[j]%2 == 1) j--;
//             if(i>=j) break;
//             swap(nums[i], nums[j]);
//         }
        
//         return nums;
//     }
// };
