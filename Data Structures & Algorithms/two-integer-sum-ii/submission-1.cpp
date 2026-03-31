class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int temp = target - nums[i];

            int lo = i + 1, hi = n - 1;

            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if(nums[mid] == temp) {
                    return {i + 1, mid + 1};
                }
                else if(nums[mid] < temp) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }

        return {};
    }
};
