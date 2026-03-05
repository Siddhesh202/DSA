class Solution {
public:
    int minOperations(string s) {
        int ans = 0, opt1 = 0, opt2 = 1, n = s.length();
        string s1 = s, s2 = s;

        // Option 1 --> Keep 1st same
        for(int i = 1; i < n; i++) {
            if(s1[i-1] == s1[i]) {
                s1[i] = (s1[i] == '0') ? '1' : '0';
                opt1++;
            }
        }

        // option 2 ---> Change 1st
        s2[0] = (s2[0] == '0') ? '1' : '0';
         for(int i = 1; i < n; i++) {
            if(s2[i-1] == s2[i]) {
                s2[i] = (s2[i] == '0') ? '1' : '0';
                opt2++;
            }
        }

        return min(opt1, opt2);
    }
};

// eg: 10010100
// Option1 : 10101010 ---> 5 operations
// Option2 : 01010101 ---> 3 operations