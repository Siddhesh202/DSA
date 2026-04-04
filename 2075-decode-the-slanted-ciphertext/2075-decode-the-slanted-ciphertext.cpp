class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.length() / rows;
        int k = 0;
        vector<vector<char>> mat(rows, vector<char>(cols, 'a'));
        string ans = "";

        // Form the matrix
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[k];
                k++;
            }
        }

        // Generate the original text from the mat
        for(int i = 0; i < cols; i++) {
            int j = 0, k = i;
            
            while(j < rows && k < cols) {
                ans += mat[j][k];
                j++, k++;
            }
        }

        int len = ans.size();
        for(int i = len-1; i >= 0; i--) {
            if(ans[i] != ' ') break;
            ans.pop_back();
        }

        return ans;
    }
};