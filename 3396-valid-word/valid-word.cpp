class Solution {
public:
    bool isValid(string word) {
        int numChar = 0, numVowels = 0, numConst = 0;

        for(auto &ch : word) {
            int ascii = ch;

            if(ch == '@' || ch == '#' || ch == '$') return false;

            else if((ascii >= 97 && ascii <= 122) || (ascii >= 65 && ascii <= 90))
            {
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                    numVowels++;
                
                else
                    numConst++;
            }

            numChar++;
        }

        if(numChar >= 3 && numVowels > 0 && numConst > 0) return true;

        return false;
    }
};