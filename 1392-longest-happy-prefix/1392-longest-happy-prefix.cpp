// Simple LPS Question
class Solution {
public:
    // string longestPrefix(string s) {
    //     int n = s.length();
    //     vector<int> LPS(n, 0);
    //     int i = 1, length = 0;

    //     while(i < n) {
    //         if(s[i] == s[length]) {
    //             length++;
    //             LPS[i] = length;
    //             i++;
    //         }
    //         else {
    //             if(length != 0)
    //                 length = LPS[length-1];
    //             else
    //                 LPS[i] = 0;
    //                 i++;            
    //             }
    //     }

    //     return s.substr(0, LPS[n-1]);
    // }
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];
            if (s[i] == s[len])
                len++;
            lps[i] = len;
        }
        return s.substr(0, lps[n - 1]);
    }
};