class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minCharToRight(n);
        string t = "", ans = "";

        minCharToRight[n-1] = s[n-1];

        for(int i = n-2; i >= 0; i--) {
            minCharToRight[i] = min(s[i], minCharToRight[i+1]);
        }

        int i = 0;

        while(i < n) {
            t.push_back(s[i]);

            int minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];

            while(t.length() > 0 && t.back() <= minChar) {
                ans.push_back(t.back());
                t.pop_back();
            }
            i++;
        }


        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};