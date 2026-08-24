class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes; //S.C: O(n)
        string res = "";

        for(string &str: strs) { //T.C: O(n)
            sizes.push_back(str.length());
        }

        for(int size: sizes) { //T.C: O(n)
            res += to_string(size) + ",";
        }

        res += '#';

        for(string str: strs) { //T.C: O(n)
            res += str;
        }

        return res; //T.C: O(n), S.C: O(n)
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes; //S.C: O(m)
        vector<string> res; //S.C: O(n)

        int i = 0;
        while(s[i] != '#') { //T.C: O(n)
            string curr = "";
            while(s[i] != ',') {
                curr += s[i++];
            }

            sizes.push_back(stoi(curr));
            i++;
        }
        i++;

        for(const int &size: sizes) { //T.C: O(N)
            res.push_back(s.substr(i, size));
            i += size;
        }

        return res;
    }
}; //T.C: O(N), S.C: O(N)
