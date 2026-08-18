class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());  // O(nLogn)

        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) { //O(n^2)
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int newTgt = -nums[i];

            int j = i + 1, k = n - 1;

            while (j < k) {
                if (nums[j] + nums[k] == newTgt) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                } else if (nums[j] + nums[k] < newTgt)
                    j++;
                else
                    k--;
            }
        }

        return result; //T.C: O(n ^ 2), S.C: O(1) except result array
    }
};