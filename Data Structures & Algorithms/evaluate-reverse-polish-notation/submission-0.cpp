class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(int i = 0; i < tokens.size(); i++) {
            string curr = tokens[i];

            if(curr == "+" || curr == "-" || curr == "*" || curr == "/") {
                string res = "";
                
                if(!st.empty()) {
                    int opr2 = stoi(st.top());
                    st.pop();
                    int opr1 = stoi(st.top());
                    st.pop();
                
                    if(curr == "+") {
                        int temp = opr1 + opr2;
                        res = to_string(temp);
                    }
                    else if(curr == "-") {
                        int temp = opr1 - opr2;
                        res = to_string(temp);
                    }
                    else if(curr == "*") {
                        int temp = opr1 * opr2;
                        res = to_string(temp);
                    }
                    else {
                        if(opr2 != 0) {
                            int temp = opr1 / opr2;
                            res = to_string(temp);
                        }
                    }
                }
                st.push(res);
            }
            else {
                st.push(curr);
            }
        }

        return st.empty() ? -1 : stoi(st.top());
    }
};
