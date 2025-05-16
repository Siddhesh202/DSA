class Solution {
public:
    int hammingDist(string s, string t) {
        if(s.length() != t.length()) return 2;
        int dist = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i]) dist++;
        }

        return dist;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> res;
        int lis = 0, lisIdx = 0;
        vector<int> dp(n, 1), parent(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i-1; j++) {

                if(groups[j] != groups[i] && hammingDist(words[i], words[j]) == 1) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                    
                    if(lis < dp[i]) {
                        lis = dp[i];
                        lisIdx = i;
                    }
                }
            }
        }

        while(lisIdx != -1) {
            res.push_back(words[lisIdx]);
            lisIdx = parent[lisIdx];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};