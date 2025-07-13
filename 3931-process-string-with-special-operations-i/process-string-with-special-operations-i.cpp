class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '*') {
                if(!res.empty()) {
                    res.pop_back();
                }
            }
            else if(ch == '#') {
                if(!res.empty()) {
                    string temp = res;
                    res += temp;
                }   
            }
            else if(ch == '%') {
                if(!res.empty()) {
                    reverse(res.begin(), res.end());
                }
            }
            else {
                res += ch;
            }
        }

        return res;
    }
};