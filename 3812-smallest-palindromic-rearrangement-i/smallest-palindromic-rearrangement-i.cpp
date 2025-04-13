class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> count(26,0);
        string leftHalf = "";
        string rightHalf = "";

        for(auto &ch : s) 
            count[ch-'a']++;
        
        for(int i = 0; i < 26; i++) {
            char ch = i + 'a';

            while(count[i] > 1) {
                leftHalf += ch;
                rightHalf += ch;
                count[i] -= 2;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] == 1)
                leftHalf += (i+'a');
        }

        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + rightHalf;
    }
};