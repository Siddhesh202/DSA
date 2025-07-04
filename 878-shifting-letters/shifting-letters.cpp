#define ll long long;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shift = 0;

        for(int i = s.length()-1; i >= 0; i--) {
            shift = (shift + shifts[i]) % 26;

            s[i] = (((s[i]-'a') + shift) % 26) + 'a';
        }

        return s;
    }
};