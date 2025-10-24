class Solution {
public:
    vector<int> digitCount = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int backtrack(int n, int curr, int digsRem) {
        if(digsRem == 0) {
            // check if balanced
            for(int dig = 1; dig < 10; dig++) {
                if(digitCount[dig] != 0 && digitCount[dig] != dig) return 0;
            }
            return curr > n ? curr : 0;
        }

        int result = 0;
        for(int dig = 1; dig <= 9; dig++) {
            if(digitCount[dig] > 0) {
                digitCount[dig]--;
                result = backtrack(n, curr*10 + dig, digsRem-1);
                if(result != 0) return result;
                digitCount[dig]++;
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n) {
        int len = to_string(n).length();

        for(int len = 1; len <= 7; len++) {
            int ans = backtrack(n, 0, len);
            if(ans != 0) return ans;
        }

        return 0;
    }
};