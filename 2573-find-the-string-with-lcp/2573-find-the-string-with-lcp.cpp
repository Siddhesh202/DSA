class Solution {
public:
    int n;
    vector<vector<int>> createLCP(string &word) {
        vector<vector<int>> lcp(n, vector<int>(n, 0));

        // Fill up the last column
        for(int row = 0; row < n; row++) lcp[row][n-1] = (word[row] == word[n-1]) ? 1 : 0;

        // Fill up last row
        for(int col = 0; col < n; col++) lcp[n-1][col] = (word[col] == word[n-1]) ? 1 : 0;

        // Now fill up remaining table using bottom up DP
        for(int row = n-2; row >= 0; row--) {
            for(int col = n-2; col >= 0; col--) {

                if(word[row] == word[col]) lcp[row][col] = 1 + lcp[row+1][col+1];
                else lcp[row][col] = 0;
            }
        }

        return lcp;
    }

    string findTheString(vector<vector<int>>& lcp) {
        n = lcp.size();

        // Find the str if possible from LCP matrix
        string word(n, '$');
        word[0] = 'a';

        for(int i = 1; i < n; i++) {
            vector<bool> forbidden(26, 0);

            for(int j = 0; j < i; j++) {
                if(lcp[j][i] == 0) forbidden[word[j]-'a'] = 1;
            }

            for(int k = 0; k < 26; k++) {
                if(!forbidden[k]) {
                    word[i] = k + 'a';
                    break;
                }
            }

            if(word[i] == '$') return ""; 
        }

        // Will cross verify by creating a lcp table
        vector<vector<int>> createdLCP = createLCP(word);
        return (lcp == createdLCP) ? word : "";
    }
};