class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;

        for(auto &word : words) {
            string revWord = word;
            swap(revWord[0], revWord[1]);

            if(mp.count(revWord) && mp[revWord] > 0) {
                ans += 4;
                mp[revWord]--;
            }
            else {
                mp[word]++;
            }
        }

        // check equal character and take one if present
        for(auto &it : mp) {
            string word = it.first;
            int count   = it.second;

            if(word[0] == word[1] && count > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};