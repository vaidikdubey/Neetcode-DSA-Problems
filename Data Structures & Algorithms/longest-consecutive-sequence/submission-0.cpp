class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        unordered_set<int> set(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int len = 0, curr = nums[i];

            while(set.find(curr) != set.end()) {
                len++;
                curr++;
            }

            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};
