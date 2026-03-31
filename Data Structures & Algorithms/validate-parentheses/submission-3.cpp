class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        if(s.length() % 2 != 0) return false;

        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '[' || ch == '{' || ch == '(') st.push(ch);
            else if(!st.empty()) {
                char top = st.top();

                if((ch == ']' && top != '[') || 
                (ch == ')' && top != '(') ||
                (ch == '}' && top != '{')) return false;
                else st.pop();
            }
        }

        return true;
    }
};
