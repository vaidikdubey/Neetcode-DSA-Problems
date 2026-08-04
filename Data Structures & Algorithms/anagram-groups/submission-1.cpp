class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tracker;

        for(int i = 0; i < strs.size(); i++) { //T.C: O(n)
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end()); //O(KLogK)

            tracker[sorted].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto &it: tracker) { //T.C: O(n)
            result.push_back(it.second);
        }

        return result; //T.C: O(N*KLogK), S.C: O(N)
    }
};
