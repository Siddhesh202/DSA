class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;

        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    vector<string> getSubstrArrays(string s) {
        vector<string> arr;
        arr.push_back("");
        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                arr.push_back(s.substr(i, j-i+1));
            }
        }

        return arr;
    }

    int longestPalindrome(string s, string t) {
        vector<string> substrArr1 = getSubstrArrays(s);
        vector<string> substrArr2 = getSubstrArrays(t);
        int ans = 0;

        // do simple concatenation
        for(int i = 0; i < substrArr1.size(); i++) {
            string substr1 = substrArr1[i];

            for(int j = 0; j < substrArr2.size(); j++) {
                string substr2 = substrArr2[j];
                
                if(isPalindrome(substr1 + substr2)) {
                    ans = max(ans * 1L, (long) substr1.length() + (long)substr2.length());
                }
            }
        }

        return ans;
    }
};