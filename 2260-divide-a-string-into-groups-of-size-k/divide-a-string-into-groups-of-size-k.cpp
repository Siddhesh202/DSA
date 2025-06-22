class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int sizeOfArr = ceil(1.0 * s.length() / k);
        for(int i = 0; i < s.length(); i+=k) {
            ans.push_back(s.substr(i, k));
        }

        while(ans[sizeOfArr-1].length() != k) {
            ans[sizeOfArr-1] += fill;
        }
        return ans;
    }
};

// 10/3 = 3
// 10%3 = 1
// 3*3