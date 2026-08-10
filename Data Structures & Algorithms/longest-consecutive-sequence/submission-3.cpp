class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tracker(nums.begin(), nums.end()); //O(n)

        int maxLen = 0, n = nums.size();

        for(int i = 0; i < n; i++) { //O(n)
            if(tracker.find(nums[i] - 1) == tracker.end()) {
                int len = 1;

                while(tracker.find(nums[i] + len) != tracker.end()) len++;

                maxLen = max(len, maxLen);
            }
        }

        return maxLen; //T.C: O(n), S.C: O(n)
    }
};
