class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tracker;

        for(int i = 0; i < strs.size(); i++) { //T.C: O(N)
            vector<int> freq(26, 0); //S.C: O(1)

            for(char ch: strs[i]) { //T.C: O(M)
                freq[ch - 'a']++;
            }

            string key = to_string(freq[0]);

            for(int i = 1; i < 26; i++) { //T.C: O(1)
                key += '#' + to_string(freq[i]);
            }

            tracker[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(const auto &it: tracker) { //T.C: O(N)
            result.push_back(it.second);
        }

        return result; //T.C: O(N * M), S.C: O(N)
    }
};
