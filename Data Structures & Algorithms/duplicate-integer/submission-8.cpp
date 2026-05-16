class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int, int> map;

       for(int num: nums) {
        map[num]++;
       }

       for(auto &[num, freq]: map) {
        if(freq > 1) return true;
       }

       return false;
    }
};