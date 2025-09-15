class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string s;
        vector<bool> isBroken(26, 0);
        stringstream ss(text);
        int ans = 0;

        for(auto &ch : brokenLetters) isBroken[ch-'a'] = 1;

        while(getline(ss, s, ' ')) {
            bool isGood = true;
            for(auto &ch : s) {
                if(isBroken[ch-'a']) {
                    isGood = false;
                    break;
                }
            }

            ans += isGood;
        }

        return ans;
    }
};