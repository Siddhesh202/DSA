class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(auto &word : words) {
            int total = 0;
            for(auto &ch : word) total += (weights[ch - 'a']);
            // cout << total << endl;
            total = total % 26;
            ans.push_back('z'-total);
        }

        return ans;
    }
};