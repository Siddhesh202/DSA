class Solution {
public:
    string helper(string s) {
        string ans = "";
        int freq = 1;
        char currEl = s[0];

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == currEl) freq++;
            else {
                ans = ans + to_string(freq) + currEl;
                freq = 1;
                currEl = s[i];
            }
        }

        ans = ans + to_string(freq) + currEl;
        
        return ans;
    }

    string countAndSay(int n) {
        string s = "1";

        for(int i = 2; i<=n; i++) {
            s = helper(s);
        }

        return s;
    }
};