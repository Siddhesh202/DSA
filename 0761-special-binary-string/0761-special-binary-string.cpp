class Solution {
public:

    string solve(string s) {
        vector<string> specials;
        string result;
        int sum = 0, start = 0;

        for(int i = 0; i < s.length(); i++) {
            sum += (s[i] == '1') ? 1 : -1;

            if(sum == 0) { // we got a special string
                string inner = s.substr(start+1, i-start-1); 
                specials.push_back("1" + solve(inner) + "0");
                start = i + 1;
            }
        }

        sort(specials.begin(), specials.end(), greater<string>());
        
        for(auto &str : specials) result += str;

        return result;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};