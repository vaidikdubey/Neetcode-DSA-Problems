class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";

        unordered_map<char, int> count, window;

        for(char ch: t) {
            count[ch]++;
        }

        int curr = 0, total = count.size();
        string res = "";
        int resLen = INT_MAX;
        int i = 0;

        for(int j = 0; j < s.length(); j++) {
            char ch = s[j];
            window[ch]++;

            if(count.find(ch) != count.end() && count[ch] == window[ch]) curr++;

            while(curr == total) {
                if((j - i + 1) < resLen) {
                    resLen = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }

                window[s[i]]--;
                if(count.find(s[i]) != count.end() && window[s[i]] < count[s[i]]) curr--;

                i++;
            }
        }

        return resLen == INT_MAX ? "" : res;
    }
};
