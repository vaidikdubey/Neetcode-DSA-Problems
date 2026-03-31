class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> complement;

        for(int i = 0; i < n; i++) {
            int comp = target - nums[i];

            if(complement.find(comp) != complement.end()) {
                return {complement[comp], i};
            }
            complement.insert({nums[i], i});
        }

        return {};
    }
};
