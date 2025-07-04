#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1)
            return 'a';

        ll len = 1, newk = 1;
        int opsType = 1;

        for(int i = 0; i < operations.size(); i++) {
            len *= 2;

            if(len >= k) {
                opsType = operations[i];
                newk = (k - len / 2);
                break;
            }
        }


        char ch = kthCharacter(newk, operations);

        if(opsType) 
            ch = (ch == 'z') ? 'a' : ch+1;
        
        return ch;
    }
};