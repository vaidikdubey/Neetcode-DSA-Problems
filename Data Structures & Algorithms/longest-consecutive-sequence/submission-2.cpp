class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxLen = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            if(set.find(nums[i] - 1) == set.end()) {
                int len = 1;
                while(set.find(nums[i] + len) != set.end()) len++;
                maxLen = max(len, maxLen);
            }
        }

        return maxLen;
    }
};
