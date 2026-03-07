class Solution {
public:
    int minFlips(string s) {
        int i = 0, j = 0, f1 = 0, f2 = 0, ans = INT_MAX;
        int n = s.length();
        s = (s + s);

        string s1, s2;
        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2) ? '0' : '1';
            s2 += (i % 2) ? '1' : '0';
        }

        // Khandaani Sliding window
        while(j < 2*n) {
            f1 += (s[j] != s1[j]) ? 1 : 0;
            f2 += (s[j] != s2[j]) ? 1 : 0;

            if(j-i+1 == n) { // Window size is reached
                ans = min(ans, min(f1, f2));

                // shrink window size by 1
                f1 -= (s[i] != s1[i]) ? 1 : 0;
                f2 -= (s[i] != s2[i]) ? 1 : 0;

                i++;
            }

            j++;
        }

        return ans;
    }
};