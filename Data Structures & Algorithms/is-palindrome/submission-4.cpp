class Solution {
    bool alphaNum(char ch) {
        return (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9');
    }

   public:
    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) { //O(n)
            while (st < end && !alphaNum(s[st])) st++;

            while (end > st && !alphaNum(s[end])) end--;

            if (tolower(s[st]) != tolower(s[end])) return false;

            st++;
            end--;
        }

        return true; //T.C: O(n), S.C: O(1)
    }
};
