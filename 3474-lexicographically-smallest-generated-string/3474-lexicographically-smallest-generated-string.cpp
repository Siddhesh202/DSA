class Solution {
public:
    bool isSame(string word, string str2, int i, int m) {
        return word.substr(i, m) == str2;
    }

    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int N = n + m - 1;

        string word(N, '$');
        vector<int> canChange(N, true);

        // Process all T's first
        for(int i = 0; i < n; i++) {

            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(word[i+j] != '$' && word[i+j] != str2[j]) return "";
                    word[i+j] = str2[j];
                    canChange[i+j] = false;
                }
            }
        }

        // Fill the remaining spaces with a
        for(int i = 0; i < N; i++) if(canChange[i]) word[i] = 'a';

        // Now process F's
        for(int i = 0; i < n; i++) {

            if(str1[i] == 'F') {

                if(isSame(word, str2, i, m)) { // Make them unequal if same
                    
                    // iterate from back since we want lexiographically smallest string
                    bool changed = false;
                    for(int j = i + m - 1; j >= i; j--) {
                        if(canChange[j]) {
                            word[j] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed) return ""; // I was not able to change any char to remove equality
                }


            }
        }

        return word;

    }
};

// s1 = TFFF , s2 = abba
// n+m-1 = 4+4-1 = 7
// word = _ _ _ _ _ _ _
// i = 0, s1 = T, word = a b b a _ _ _ 
// i = 1, s2 = F, word = 
// i = 2, s2 = F, word = 
// i = 3, s2 = T, word = a b b a b b a