class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), res = 0;
        vector<int> prefOne(n, 0);
        prefOne[0] = (s[0] == '1') ? 1 : 0;

        // 1. make prefix sum
        for(int i = 1; i < n; i++) prefOne[i] = prefOne[i-1] + ((s[i] == '1') ? 1 : 0);

        // [i....j] = prefOne[j] - prefOne[i-1] ------>get count of One
        // 2. Apply n * root(n) approach
        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                int oneCnt = prefOne[j] - ((i > 0) ? prefOne[i-1] : 0);
                int zeroCnt = (j - i + 1) - oneCnt; // len - oneCnt

                // 3 Cases
                if((zeroCnt * zeroCnt) > oneCnt) {
                    int needOne = (zeroCnt * zeroCnt) - oneCnt;
                    j += needOne - 1; // since for loop ek j aur jyada hoga, isliye minus minus
                }
                else if((zeroCnt * zeroCnt) == oneCnt) {
                    res++;
                }   
                else { // (zeroCnt * zeroCnt) < oneCnt
                    int k = sqrt(oneCnt) - zeroCnt;
                    int nextj = j + k;
                    res++;

                    if(nextj >= n) { // out of bound ho gaya
                        res += (n-j-1);
                        break;
                    } 
                    else {
                        res += k;
                    }

                    j = nextj;
                }
            }
        }

        return res;
    }
};