class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        //Map for storing the sorted word and index pairs
        unordered_map<string, vector<int>> map;

        //Finding indexes of all anagrams
        for(int i = 0; i < n; i++) {
            string word = strs[i];

            sort(word.begin(), word.end());

            map[word].push_back(i);
        }

        vector<vector<string>> result;

        //Find and store all anagram groups in result
        for(auto &[word, arr]: map) {
            vector<string> temp;

            for(int i = 0; i < arr.size(); i++) {
                temp.push_back(strs[arr[i]]);
            }

            result.push_back(temp);
        }

        return result;
    }
};
