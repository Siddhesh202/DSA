class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";

        while(ans.length() < k) {
            int len = ans.length();

            for(int i = 0; i < len; i++) {
                int nextChar = ((ans[i]-'a') + 1) % 26;
                ans += (nextChar+'a');
            }
        }

        return ans[k-1];
    }
};