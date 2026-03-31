class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dupes;
        int i = 0, j = 0, len = 0;

        while(j < s.length()) {
            while(dupes.find(s[j]) != dupes.end()) {
                dupes.erase(s[i]);
                i++;
            }
            dupes.insert(s[j]);
            j++;
            len = max(len, j - i);
        }

        return len;
    }
};
