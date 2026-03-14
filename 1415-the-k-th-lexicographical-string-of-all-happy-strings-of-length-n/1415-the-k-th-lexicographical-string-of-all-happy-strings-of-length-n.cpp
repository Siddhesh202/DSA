class Solution {
public:
    vector<char> chars = {'a', 'b', 'c'};
    vector<string> result;

    void solve(int n, string &curr) {
        if(curr.length() == n) {
            result.push_back(curr);
            return;
        }

        int i = curr.length();
        for(auto &ch : chars) {
            if(curr.empty() || ch != curr[i-1]) {
                curr.push_back(ch);
                solve(n, curr);
                curr.pop_back();
            }
        }
    } 

    string getHappyString(int n, int k) {
        string curr = "";

        solve(n, curr);

        if(k > result.size()) return "";

        return result[k-1];
    }
};