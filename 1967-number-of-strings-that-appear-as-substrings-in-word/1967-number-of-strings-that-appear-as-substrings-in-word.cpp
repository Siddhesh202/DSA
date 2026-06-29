class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0, n = word.length();

        for(auto &pattern : patterns) {
            if (word.find(pattern) != string::npos)
                ans++;
        }

        return ans;
    }
};