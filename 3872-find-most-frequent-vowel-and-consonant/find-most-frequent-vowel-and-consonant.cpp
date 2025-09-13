class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int vow = 0, cons = 0;

        for(auto &ch : s) freq[ch-'a']++;

        for(int i = 0 ; i < 26; i++) {
            char ch = i + 'a';
            int fr = freq[i];

            if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u') {
                vow = max(vow, fr);
            }
            else
                cons = max(cons, fr);
        }

        return vow + cons;
    }
};