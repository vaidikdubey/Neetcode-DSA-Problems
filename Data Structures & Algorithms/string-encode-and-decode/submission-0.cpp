class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        string res = "";

        for(string &str: strs) {
            sizes.push_back(str.length());
        }
        for(int size: sizes) {
            res += to_string(size) + ',';
        }

        res += '#';

        for(string &str: strs) {
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes;
        vector<string> res;

        int i = 0;

        while(s[i] != '#') {
            string curr = "";
            while(s[i] != ',') {
                curr += s[i++];
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++; //Skipping '#' to move to actual appended strings
        for(int size: sizes) {
            res.push_back(s.substr(i, size));
            i += size;
        }

        return res;
    }
};
