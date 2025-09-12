class Solution {
public:
    bool doesAliceWin(string s) {
        int cntVow = 0;

        for(auto &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                cntVow++;
        }

        // cout << cntVow;

        return cntVow != 0;
    }
};