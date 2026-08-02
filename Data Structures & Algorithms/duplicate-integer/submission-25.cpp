class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      int n = nums.size();

      unordered_set<int> tracker;

      for(int i = 0; i < n; i++) {
        if(tracker.find(nums[i]) != tracker.end()) return true;
        tracker.insert(nums[i]);
      }

      return false;
    }
};