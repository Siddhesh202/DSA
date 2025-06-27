class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string &curr, int k) {
        int n = s.length();
        int L = curr.length();
        int i = 0;
        int j = 0;

        while(i < n && j < (k * L)) {
            if(s[i] == curr[j%L]) {
                j++;
            }
            i++;
        }

        if(j == (k * L)) return true;
        return false;
    }

    void backtracking(string &s, string &curr, vector<bool> &canUse, vector<int> &reqFreq, int k, int maxLen) {
        if(curr.length() > maxLen) return;

        if(((curr.length() > result.length()) || ((curr.length() == result.length()) && (curr > result)))
        && isSubsequence(s, curr, k)) result = curr;

        for(int i = 0; i < 26; i++) {
            if(canUse[i] && reqFreq[i] > 0) {
                curr += (i+'a');
                reqFreq[i]--;
                backtracking(s, curr, canUse, reqFreq, k, maxLen);
                curr.pop_back();
                reqFreq[i]++;
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26,0);
        vector<bool> canUse(26, false);
        vector<int> reqFreq(26, 0);

        // 1. Store freq of each char
        for(auto &ch : s) freq[ch-'a']++;

        // 2. Filter our char whose freq >= k & Find atmost freq of a char that can be used using freq[i] / k;
        // l -> 2/2 = 1 ,  e -> 4/2 = 2 ,  t -> 2/2 = 1
        for(int i = 0; i < 26; i++) {
            if(freq[i] >= k) {
                canUse[i] = true;
                reqFreq[i] = freq[i] / k;
            }
        }

        // 3. Generate all subsequences and check
        int maxLen = n / k;
        string curr;

        backtracking(s, curr, canUse, reqFreq, k, maxLen);

        return result;

    }
};