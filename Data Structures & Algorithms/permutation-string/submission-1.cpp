class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        unordered_map<char, int> mapS1;

        for(auto ch: s1) {
            mapS1[ch]++;
        }

        int need = mapS1.size();

        for(int i = 0; i < m; i++) {
            unordered_map<char, int> mapS2;

            int curr = 0;

            for(int j = i; j < m; j++) {
                char ch = s2[j];

                mapS2[ch]++;

                if(mapS1[ch] < mapS2[ch]) break;

                else if(mapS1[ch] == mapS2[ch]) curr++;

                if(curr == need) return true;
            }
        }

        return false;
    }
};
