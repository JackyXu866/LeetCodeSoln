class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rt;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0; i<n-1; i++){
            int target = -nums[i];
            int low = i+1, high = n-1;

            while(low < high){
                if(nums[low] + nums[high] < target) low++;
                else if(nums[low] + nums[high] > target) high--;
                else{
                    cout << low << ", " << high << endl;
                    rt.push_back({nums[i], nums[low], nums[high]});
                    int ogl = low, ogh = high;
                    while(low < high && nums[low] == nums[ogl]) low++;
                    while(low < high && nums[high] == nums[ogh]) high--;
                }
            }

            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }

        return rt;
    }
};
